//Problem from https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

//Algorithm implemented based on 
//Tushar roy explanation - https://www.youtube.com/watch?v=13m9ZCB8gjw

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
    TreeNode* lca(TreeNode* root, TreeNode* left, TreeNode* right)
    {
      if (root == NULL) return NULL;
      if (root == left || root == right) return root;
      auto leftNode  = lca(root->left, left, right);
      auto rightNode = lca(root->right, left, right);
      if (leftNode && rightNode) return root;
      if (leftNode == NULL && rightNode == NULL) return NULL;
      if (!leftNode && rightNode) return rightNode;
      return leftNode;
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
        
        return lca(root, p, q);
    }
};