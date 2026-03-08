//二叉树的前中后序遍历，使用“颜色标记法”能对这三种遍历写出大致相同的代码，更容易理解
//经历过的节点变为灰色
//主要函数

#define white 0
#define gray 1

//二叉树节点结构
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//存放节点栈的结构
typedef struct{
    int color;
    struct TreeNode *node;
}stackElement;

int* Traversal(struct TreeNode *root,int *resSize){
    //定义存放结果的数组
    int *res = malloc(sizeof(int) * 501);

    //定义栈顶指针
    int stackTop = -1;
    *resSize = 0;
    stackElement *stack = malloc(sizeof(stackElement) * 501);
    stack[++stackTop] = (stackElement){white,root};

    while(stackTop >= 0){
        stackElement elem = stack[stackTop--];
        struct TreeNode* node = elem.node;

        if(node == NULL) continue;

        //中序遍历,因为栈是先进后处，中序为左-根-右，进栈的顺序为右-根-左
        //前序，后序代码一样，就是修改了进栈顺序
        if(elem.color == white){
            stack[++stackTop] = (stackElement){white,node->right};
            stack[++stackTop] = (stackElement){gray,node};
            stack[++stackTop] = (stackElement){white,node->left};
        }
        else{
            res[(*resSize)++] = node->val;
        }
    }
    free(stack);
    return res;
}