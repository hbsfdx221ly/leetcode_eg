
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


#include <unordered_map>
#include <list>

class Solution
{
public:
    Node* copyrandomList(Node* head){
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node* , Node*> map;//定义了一个无序哈希表
        while(cur != nullptr){
            map[cur] = new Node(cur->val);//map[cur]返回的是一个空指针，new Node在堆上创建一个新节点并返回地址，这样就建立了一个节点对
            cur = cur->next;
        }
        cur = head;
        while(cur != nullptr){
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};


