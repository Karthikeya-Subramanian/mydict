#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
/*
    1.operator[]                returns the reference to the value of the key
    2.display                   display
    3.sort                      ascending sort
    4.Assignment Operator =
    5.Copy constructor
    6.Equivalence operator ==
    7.pop                       pops the last element from the list
    8.clear                     clears the entire list
    9.keys                      that return all the keys as an array
    10.values                   returns all the values as an array
*/
template<class T1,class T2>
struct Node{
    public:
    T1 f;
    T2 s;
    Node* right;
    Node* left;
    Node();
};
template<class T1,class T2>
class mydict{

        Node<T1,T2> *head,*I;
        int n;
        T1 *F;
        T2 *S;
    public:
        friend class Node<T1,T2>;
        mydict();
        mydict(T1 *in,T2 *in1,int n);
        mydict(const mydict &a);
        T2& operator [](T1 st);
        void display();
        void sort();
        mydict& operator =(const mydict &a);
        bool operator ==(const mydict a);
        bool pop(T1 a);
        int size();
        bool clear();
        void setvalues();
        void setkeys();
        T1* keys();
        T2* values();
        ~mydict();
};






template<class T1,class T2>
 Node<T1,T2>::Node(){
        right=left=NULL;
        s=0;
}
template<class T1,class T2>
mydict<T1,T2>::mydict(){
            head=NULL;
            I=NULL;
            n=0;
}
template<class T1,class T2>
int mydict<T1,T2>::size(){
    return n;
}
template<class T1,class T2>
mydict<T1,T2>::mydict(T1 *in,T2 *in1,int n)
{
            this->n=n;
            Node<T1,T2> *temp;
            temp=new Node<T1,T2>;
            temp->f=in[0];
            temp->s=in1[0];
            head=temp;
            I=temp;
            head->left=head->right=head;
            for(int i=1;i<n;i++){
                Node<T1,T2> *temp;
                temp=new Node<T1,T2>;
                temp->f=in[i];
                temp->s=in1[i];
                I->right=temp;
                temp->left=I;
                head->left=temp;
                temp->right=head;
                I=temp;
            }
}
template<class T1,class T2>
mydict<T1,T2>::mydict(const mydict &a)
{
     *this=a;
}
template<class T1,class T2>
bool mydict<T1,T2>::pop(T1 a)
{
        Node<T1,T2> *temp=head;
        while(temp->right!=head){
            if(temp->f==a){
                (temp->left)->right=temp->right;
                (temp->right)->left=temp->left;
                if(head==temp)
                    head=temp->right;
                free(temp);
                n--;
                return true;
            }
            temp=temp->right;
        }
         if(temp->f==a){
                (temp->left)->right=temp->right;
                (temp->right)->left=temp->left;
                free(temp);
                n--;
                return true;
            }
            else
            {
                cout<<"No such element found\n";
                return false;
            }

}
template<class T1,class T2>
bool mydict<T1,T2>::operator ==(const mydict<T1,T2> a)
{
        if(this->n==a.n){
            Node<T1,T2> *temp1=head;
            Node<T1,T2> *temp2=a.head;
            while(temp1->right!=head&&temp2->right!=a.head){
                if(temp1->f==temp2->f)
                {
                    if(temp1->s==temp2->s)
                    {
                        temp1=temp1->right;
                        temp2=temp2->right;
                    }
                    else
                        break;
                }
                else
                    break;
        }
        if(temp1->f==temp2->f)
        {
                    if(temp1->s==temp2->s)
                    {
                        return true;
                    }
                    else
                        return false;
        }
        else
            return false;
    }
        return false;
}
template<class T1,class T2>
mydict<T1,T2>& mydict<T1,T2>::operator =(const mydict &a){
        this->n=a.n;
        Node<T1,T2> *temp,*temp1=a.head;
            temp=new Node<T1,T2>;
            temp->f=temp1->f;
            temp->s=temp1->s;
            head=temp;
            I=temp;
            head->left=head->right=head;
            temp1=temp1->right;
            while(temp1!=a.head){
                Node<T1,T2> *temp;
                temp=new Node<T1,T2>;
                temp->f=temp1->f;
                temp->s=temp1->s;
                I->right=temp;
                temp->left=I;
                head->left=temp;
                temp->right=head;
                I=temp;
                temp1=temp1->right;
            }

}
template<class T1,class T2>
void mydict<T1,T2>::sort(){
        int i=0;
        T2 swap;
        T1 swapb;
        Node<T1,T2> *temp=head;
        while(temp->right!=head){
            T2 &a=temp->s;
            T1 &b=temp->f;
            Node<T1,T2> *temp1=temp->right;
            while(temp1!=head){
                if(a>temp1->s){
                    swapb=b;
                    b=temp1->f;
                    temp1->f=swapb;
                    swap=a;
                    a=temp1->s;
                    temp1->s=swap;
                }
                temp1=temp1->right;
            }
            temp=temp->right;
        }

}
template<class T1,class T2>
T2& mydict<T1,T2>::operator [](T1 st){
            Node<T1,T2> *temp=head,*temp1;
           int c=0,t=n;
        while(t--){
                if(temp->f==st)
                    {
                        c++;
                        break;

                    }
                temp=temp->right;
            }
        if(c==0){
                temp1=new Node<T1,T2>;
                temp1->f=st;
                temp1->right=head;
            if(head==NULL){
                head=temp1;
                head->left=temp1;
                head->right=temp1;
                I=head;
                }
            else{
                I->right=temp1;
                temp1->left=I;
                head->left=temp1;
                I=temp1;
                }
            n++;
        }
        else{
                temp1=temp;
        }
        return temp1->s;
}
template<class T1,class T2>
void mydict<T1,T2>::display(){
        Node<T1,T2> *temp=head;
        int t=n;
        while(t--){
            cout<<"Key: "<<temp->f<<" value: "<<temp->s<<endl;
            temp=temp->right;
        }
}
template<class T1,class T2>
bool mydict<T1,T2>::clear(){
        Node<T1,T2> *temp=head;
        for(int i=0;i<n;i++){
            temp=head->right;
            free(head);
        }
        n=0;
        return 1;
}
template<class T1,class T2>
T2* mydict<T1,T2>::values(){
        setvalues();
        return S;
}
template<class T1,class T2>
T1* mydict<T1,T2>::keys(){
        setkeys();
        return this->F;
}
template<class T1,class T2>
void mydict<T1,T2>::setvalues(){
            Node<T1,T2> *temp=head;
            S=new T2[n];
            for(int i=0;i<n;i++){
                S[i]=temp->s;
                temp=temp->right;
            }
}
template<class T1,class T2>
void mydict<T1,T2>::setkeys(){
            Node<T1,T2> *temp=head;
            F=new T1[n];
            for(int i=0;i<n;i++){
                F[i]=temp->f;
                temp=temp->right;
        }
}
template<class T1,class T2>
mydict<T1,T2>::~mydict(){
        Node<T1,T2> *temp=head;
        for(int i=0;i<n;i++){
            temp=head->right;
            free(head);
        }
}

