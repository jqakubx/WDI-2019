#include<iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
void insert_list(node *&f, int x)
{
    node *r = new node, *p = f;
    r->val = x;
    r->next = NULL;
    if(f==NULL) {f = r; return;}
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next = r;
}
int unical(node *&f)
{
    int deleted = 0;
    node *left = f, *prev = NULL;
    if(left == NULL or left->next == NULL) return 0;
    node *right = f->next, *tmp;
    while(right != NULL)
    {
        if(left->val == right->val)
        {
             while(right != NULL and left->val == right->val)
             {
                right = right -> next;
             }
             while(left != right)
             {
                tmp = left;
                left = left->next;
                delete tmp;
                deleted++;
             }
        }
        if(left == NULL) return deleted;
        if(left == right)right = left->next; else{if(right!=NULL){left = right;right=right->next;}}
        if(prev == NULL) f = left; else {prev->next = left;}
        if(right == NULL or right->val != left->val)
            prev = left;
    }
    return deleted;
}
int main()
{
    node *f = NULL;
    insert_list(f, 2);
    insert_list(f, 2);
    insert_list(f, 2);
    insert_list(f, 3);
    insert_list(f, 3);
    insert_list(f, 4);
    insert_list(f, 4);
    insert_list(f, 5);
    insert_list(f, 8);
    insert_list(f, 8);
    insert_list(f, 11);
    cout << unical(f);
}
