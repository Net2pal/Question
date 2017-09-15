/*************
 Given a sorted doubly linked list of positive distinct elements, the task is to print pairs in input list whose sum is equal to given integer x. Try doing it without using any extra space. If there are no such pairs, you are not required to print anything. Order of pairs doesn't matter
 
 Following is the Node structure already written.

 template <typename T>
 class Node {
    public:
        T data;
        Node* next;
        Node* prev;
 
        Node(T data) {
            next = NULL; prev=NULL;
            this->data = data;
        }
 
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
 };
 
*************/


void pairSum(Node<int>* head, int x) 
{
	Node<int>* first=head;
	Node<int>* second=head;
	while (second->next != NULL)
         second = second->next;
		 bool found=false;
		 while (first != NULL && second != NULL && first != second && second->next != first)
		 {
			if((first->data+second->data)==x)
			{
				cout<<first->data<<" "<<second->data;
				found=true;
				first=first->next;
				second=second->prev;
			}
			else 
			{
				 if ((first->data + second->data) < x)
                 first = first->next;
              else
                 second = second->prev;
			}
		}
		 if (found == false)
          cout<<" ";
}