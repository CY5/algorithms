#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> AddTwoBinaryArray(const vector<int>& A, const vector<int>& B)
{
    int lenA = static_cast<int>(A.size())-1;
    int lenB = static_cast<int>(B.size())-1;
    int n = max(lenA, lenB);
    vector<int> C;
    int carry = 0;
    while(lenA>=0 || lenB>=0 || carry==1)
    {
        int a = (lenA>=0)?A[lenA--]:0;
        int b = (lenB>=0)?B[lenB--]:0;
        int sum = a + b + carry;
        C.push_back(sum%2);
        carry = sum / 2;
    }
    std::reverse(C.begin(),C.end());
    return C;
}

int main()
{
    vector<int> A = {1,1};
    vector<int> B = {1};
    vector<int> C = AddTwoBinaryArray(A, B);
    for(int i : C)
    {
        cout << i <<",";
    }
    cout << "\n";
    return 0;
}