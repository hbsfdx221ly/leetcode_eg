//c++定义结构体
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//c语言定义结构体
 struct ListNode {
    int val;
    struct ListNode *next;
 };

class Solution{
public:
    ListNode* insertionSortList(ListNode* head){
        //等于空的关键字不相同
        if(head == nullptr)//if(head == NULL)
            return head;
        
        //创建新的节点的方式不同
        ListNode *dummyhead = new ListNode(0);//c: struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        dummyhead->next = head;
        ListNode *lastStored = head;
        ListNode *curr = head->next;
        while(curr != nullptr){
            if(lastStored->val <= curr->val){
                lastStored = curr;
                curr = curr->next;
            }else{
                ListNode *prve;
                prve = dummyhead;
                while(prve->next->val <= curr->val){
                    prve = prve->next;
                }
                lastStored->next = curr->next;
                curr->next = prve->next;
                prve->next = curr;
            }
        }
        return dummyhead->next;
    }
};