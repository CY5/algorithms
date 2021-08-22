//Problem from https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

//Algorithm implemented based on https://www.cis.upenn.edu/~matuszek/cit594-2012/Pages/backtracking.html

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    struct Node
    {
      Node(TreeNode* rt, bool left, bool right):root(rt),leftVisited(left),rightVisited(right)
      {
        
      }
      TreeNode* root;
      bool leftVisited;
      bool rightVisited;
    };
    vector<TreeNode*> lowestCommonAncestor(TreeNode* root, int val)
    {
      stack<Node> st;
      st.emplace(root, false, false);
      while(!st.empty())
      {
        auto& topNode = st.top();
        if (topNode.root->val == val)
        {
          break;
        }
        if (topNode.root->left == NULL && topNode.root->right == NULL)
        {
          st.pop();
        }
        else
        {
          if (!topNode.leftVisited && topNode.root->left)
          {
            st.emplace(topNode.root->left, false, false);
            topNode.leftVisited = true;
          }
          else if (!topNode.rightVisited && topNode.root->right)
          {
            st.emplace(topNode.root->right, false, false);
            topNode.rightVisited = true;
          }
          else
          {
            st.pop();
          }
        }
      }
      int n = st.size();
      vector<TreeNode*> li(n,NULL);
      for(int i=n-1;i>=0;i--)
      {
        auto top = st.top();
        li[i] = top.root;
        st.pop();
      }
      return li;
    }
    void printNode(vector<TreeNode*> t)
    {
      cout <<":";
      for(auto t1: t)
      {
        cout << t1->val<<",";
      }
      cout<<"\n";
    }
      
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr)
          return NULL;
        vector<TreeNode*> l1 = lowestCommonAncestor(root, p->val);
        
        vector<TreeNode*> l2 = lowestCommonAncestor(root, q->val);
        int n = min(l1.size(),l2.size());
        TreeNode* rt = root;
        //printNode(l1);
        //printNode(l2);
        for(int i=0;i<n;i++)
        {
          if (l1[i]->val!=l2[i]->val)
          {
            break;
          }
          rt = l1[i];
        }
        return rt;
    }
};