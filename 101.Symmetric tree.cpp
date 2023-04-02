class Solution {
public:
    bool isMirrored(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL)return true;
        else if(root1==NULL || root2==NULL)return false;
        
        return (root1->val==root2->val)&&isMirrored(root1->left,root2->right)&&isMirrored(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirrored(root,root);   
    }
};
