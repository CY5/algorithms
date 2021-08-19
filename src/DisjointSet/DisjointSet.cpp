#include <iostream>
#include <unordered_map>
#include <memory>

class Disjoint
{
    private:
        struct Node
        {
            long data = 0L;
            std::weak_ptr<Node> parent;
            int rank = 0L;
        };
    public:
    using spNode = std::shared_ptr<Node>;
    using wpNode = std::weak_ptr<Node>;
    Disjoint()
    {
    }
    ~Disjoint()
    {

    }
    void makeSet(long nData)
    {
        spNode node = std::make_shared<Node>();
        node->data = nData;
        node->parent = node;
        node->rank = 0;
        mp[nData] = node;
    }
    void unionSet(long nData1, long nData2)
    {
        spNode node1 = nullptr;spNode node2=nullptr;
        auto iterMp1 = mp.find(nData1);
        if (iterMp1 != mp.end())
        {
            node1 =  iterMp1->second;
        }
        auto iterMp2 = mp.find(nData2);
        if (iterMp2 != mp.end())
        {
            node2 =  iterMp2->second;
        }
        if (node1==nullptr || node2==nullptr)
        {
            return;
        }
        spNode parent1 = findSet(node1).lock();
        spNode parent2 = findSet(node2).lock();

        if ((parent1==nullptr || parent2==nullptr) ||
            (parent1->data == parent2->data))
            {
                return;
            }
        if (parent1->rank >= parent2->rank)
        {
            parent1->rank = (parent1->rank == parent2->rank)?
                            parent1->rank+1:parent1->rank;
            parent2->parent = parent1;
        }
        else
        {
            parent1->parent = parent2;
        }
    }
    long findSet(long data)
    {
        auto iterMp1 = mp.find(data);
        if (iterMp1 != mp.end())
        {
            if (auto node = findSet(iterMp1->second).lock())
            {
                return node->data;
            }
        }
        return 0; 
    }
    wpNode findSet(spNode node)
    {
        if (node == nullptr)
        {
            return wpNode();
        }
        if (auto parent = node->parent.lock())
        {
            if (parent == node)
            {
                return parent;
            }
            node->parent = findSet(parent);
            return node->parent;
        }
        return wpNode();
    }
    private:

        std::unordered_map<long, spNode> mp;
};

int main()
{
    Disjoint ds;
    for(long i=1;i<=7;i++)
    {
        ds.makeSet(i);
    }
    ds.unionSet(1,2);
    ds.unionSet(2,3);
    ds.unionSet(4,5);
    ds.unionSet(6,7);
    ds.unionSet(5,6);
    ds.unionSet(3,7);

    for(long i=1;i<=7;i++)
    {
        std::cout << ds.findSet(i)<<"\n";
    }
    return 0;
}