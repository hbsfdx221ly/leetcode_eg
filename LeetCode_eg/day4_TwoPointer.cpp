//1.使用双指针来判断单链表是否有环
// Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  };

//使用快慢指针，快指针每次走两步，慢指针每次走一步，当有环时，快指针会重新追上慢指针
class Solution{
public:
    bool hasCycle(ListNode *head){
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast != nullptr){
            fast = fast->next;
            if(fast != nullptr)
                fast = fast->next;
            if(fast == slow)
                return true;
            slow = slow->next;
        }
        return false;
    }
};

//使用快慢指针来判断环的长度,当快慢指针第一次相遇后到它们的第二次的相遇，走过的步数就是环的长度
class Solution2{
public:
    int hasCycle(ListNode* head){
        ListNode *fast,*slow;
        int flag = 0;
        int flag1 = 0;
        int count = -1;
        fast = slow = head;
        while(fast != nullptr){
            fast = fast->next;
            if(fast != nullptr)
                fast = fast->next;
            if(slow == fast){
                flag = 1;
                flag1++;
            }
            if(flag == 1 && flag1 == 1)
                count++;
            slow = slow->next;
        }
        return count;
    }
};

//使用快慢指针来获取单链表倒数第k个节点
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
public:
    ListNode* traningplan(ListNode* head,int k){
        ListNode *p,*q;
        q = p = head;
        while(k--){
                p = p->next;
        }
        while(p != nullptr){
            p = p->next;
            q = q->next;
        }
        return q;
    }
};

//使用快慢指针来获取一个单链表中间的节点，快指针每次走两步，慢指针每次走一步
//当链表长度为奇数时，慢指针刚好指向中间节点。当长度为偶数时，指向中间两个节点前面的那个

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* middle(ListNode* head){
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;//当长度为偶数时，fast指向null,但是slow还是会向后走一格，再经过判断结束循环
            slow = slow->next;//当当长度为奇数时，fast->next指向null,再经过判断结束循环
        }
    }
};

