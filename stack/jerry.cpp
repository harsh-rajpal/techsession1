#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<cstdio>
#include<stdbool.h>
using namespace std;
/* List-A program to merge two independent list having detail of student and merge them in ascending order*/

/* Queue- A program to handle a group of people in a queue for roller coaster ride.
    It has a capacity of 5 people and give preference to come in front to VIP people.*/
/*Topics covered:
    1. sorting
        Bubble, selection, insertion, merge, radix, quick, heap, shell.
    2. Searching
        linear, binary, ternary.
    3. Data structure
        1.stack
            i. push, pop, empty, full. (in both dynamic and array implementation).
        2. queue
            i. Regular
                -push, pop, empty, full. (in both dynamic and array implementation).
            ii. Double Ended
                -push front, push back, pop front, pop back, empty, full. (in both dynamic and array implementation).
        3. Circular queue
             i. Regular
                -push, pop, empty, full. (in both dynamic and array implementation).
            ii. Double Ended
                -push front, push back, pop front, pop back, empty, full. (in both dynamic and array implementation).
        4. Tree
        5. Graph Theory
        6. Hash
*/

void swap(int *x ,int *y)
{
int temp=*x;
*x=*y;
*y=temp;
}
void selection(int a[], int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        swap(&a[min],&a[i]);
    }
}
void insertion(int a[], int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void bubble(int a[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
            {
                swap(&a[j], &a[j+1]);
            }
    }
}
void merge(int a[], int l, int m, int r);
void merge_Sort(int a[], int l, int r)
{
    int m;
    if(l<r)
    {
        m=l+(r-l)/2;
        merge_Sort(a,l,m);
        merge_Sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
void merge(int a[], int l, int m, int r)
{
    int i,j,k,n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(i=0;i<n2;i++)
        R[i]=a[m+1+i];
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}
void shell(int a[], int n)
{
    int temp,g,i,j;
    for(g=n/2;g>0;g/=2)
    {
        for(i=g;i<n;i++)
        {
            temp=a[i];
            for(j=i;j>=g && a[j-g]>temp;j-=g)
            {
                a[j]=a[j-g];
            }
            a[j]=temp;
        }
    }
}
int get_max(int a[], int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];
    return m;
}
void count_sort(int a[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (a[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (a[i]/exp)%10 ] - 1] = a[i];
        count[ (a[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        a[i] = output[i];
}
void radix(int a[], int n)
{
    int m = get_max(a, n);

    for (int exp = 1; m/exp > 0; exp *= 10)
        count_sort(a, n, exp);
}
 int partition (int a[], int l , int h)
{
    int pivot=a[h],i=l-1,j;
    for(j=l;j<=h-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    return i+1;
}
void quick(int a[], int l , int h)
{
    if(l<h){
        int j=partition(a,l,h);
        quick(a,l,j-1);
        quick(a,j+1,h);
    }
}
void heapify (int a [], int n, int i)
{
    int lgt = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[lgt])
        lgt = l;
    if (r < n && a[r] > a[lgt])
        lgt = r;
    if (lgt != i)
    {
        swap(a[i], a[lgt]);
        heapify(a, n, lgt);
     }
}
void heap (int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify (a, n, i);
     for (int i=n-1; i>=0; i--)
    {
        swap (a [0], a[i]);
        heapify (a, i, 0);
    }
}
bool linear_search(int a[], int n, int k)
{
    int i;
    for(i=0;i<n;i++)
        if(k==a[i])
            return true;
    return false;
}
bool binary_search(int a[], int n, int k)
{
    int l=0,r=n-1,mid;
    while(r>=l)
    {
        mid=l+(r-l)/2;
        if(a[mid]==k)
            {
                return true;
            }
        else if(k>a[mid])
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return false;
}
bool ternary_search(int l, int r, int key, int a[])
{
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (a[mid1] == key) {
            return true;
        }
        if (a[mid2] == key) {
            return true;
        }
        if (key < a[mid1]) {
            return ternary_search(l, mid1 - 1, key, a);
        }
        else if (key > a[mid2]) {
            return ternary_search(mid2 + 1, r, key, a);
        }
        else {
            return ternary_search(mid1 + 1, mid2 - 1, key, a);
        }
    }
    return false;
}
void  display(int a[], int n)
{
        int i;
        cout<<"\t\t";
        for(i=0;i<n;i++)
        {
            cout<<" ["<<a[i]<<"] ";
        }
        cout<<endl;
}
void reset(int a[], int b[], int n)
{
    int i;
    for(i=0;i<n;i++)
        a[i]=b[i];
}
class Stack
{
private:
    int top, a[20],capacity;
public:
    Stack(int n)
    {
        top=-1;
        capacity=n;
    }
    bool isempty();
    bool isfull();
    bool push(int val);
    bool pop();
    void print();
};
bool Stack :: isempty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
bool Stack :: isfull()
    {
        if(top==capacity)
            return true;
        else
            return false;
    }
bool Stack :: push(int val)
{
    if(isfull())
        return false;
    else
    {
        a[++top]=val;
        return true;
    }
}
bool Stack :: pop()
{
    if(isempty())
        return false;
    else
    {
        top--;
        return true;
    }
}
void Stack :: print()
{
    cout<<"\n\t\tIt has a capacity of "<<capacity+1<<" and it has "<<top+1<<" elements in it"<<endl;
    if(isempty())
        cout<<"\t\tStack is empty\n";
    else
    {
        cout<<"\t\tValues in the stack\n";
        int i;
        cout<<endl;
        for(i=top; i>=0;i--)
        cout<<"\t [ "<<a[i]<<" ]";
        cout<<endl;
    }
}
class stack_linked
{
public:
    string name;
    stack_linked *next;
    stack_linked()
    {
        name="";
        next=NULL;
    }
};
class stack_operation
{
public:
    stack_linked *head;
    stack_linked *current;
    stack_operation()
    {
        head=current=NULL;
    }
    void shifting(int n);
    bool add(stack_linked *n);
    void display();
};
void stack_operation :: shifting(int n)
{
    if(n==-1)
    {
        if(head->next==NULL || head==NULL)
        cout<<"\t\tThere is no page behind!!"<<endl;
        else
        {
            stack_linked *temp=head;
            while(temp->next!=current)
                temp=temp->next;
            current=temp;
            cout<<"\t\t You are currently on "<<current->name<<endl;
        }
    }
    else if(n==0)
    {
        if(head==NULL)
            cout<<"\t\tThere is no page!!\n";
        else
            cout<<"\t\t You are currently on "<<current->name<<endl;
    }
    else if(n==1)
    {
        if(head==NULL || current->next==NULL)
            cout<<"\t\tThere is no page!!\n";
        else
            {
                current=current->next;
                cout<<"\t\t You are currently on "<<current->name<<endl;
            }
    }
}
bool stack_operation :: add(stack_linked *n)
{
    if(head==NULL)
        {
            head=current=n;
            return true;
        }
    else
    {
        current->next=n;
        current=n;
        return true;
    }
    return false;
}
void stack_operation :: display()
{
    if(head==NULL)
        cout<<"\t\tThere is nothing to print!!!\n";
    else
    {
        stack_linked *temp=head;
        cout<<"\t\t";
        while(temp!=NULL)
        {
            cout<<temp->name<<" --> ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
class tree
{
public:
    int data;
    tree *lc,*rc;
    tree(int val)
    {
        data=val;
        lc=rc=NULL;
    }
};
class tree_operation
{
public:
    tree *root;
    tree_operation()
    {
        root=NULL;
    }
    tree * nodeCreation(int val);
    tree * insertion(tree *t, int val);
    tree * minval(tree *t);
    tree * deletion(tree *t, int val);
    void inorder(tree *r);
    void postorder(tree *r);
    void preorder(tree *r);
};
tree * tree_operation :: nodeCreation(int val)
{
    tree *t=new tree(val);
    return t;
}
tree * tree_operation :: insertion(tree *t, int val)
{
    if(t==NULL)
        return nodeCreation(val);
    if(val < t->data)
        t->lc=insertion(t->lc,val);
    else
        t->rc=insertion(t->rc,val);
    return t;
}
tree * tree_operation :: minval(tree *t)
{
    tree * current=t;
    while(current && current->lc != NULL)
        current=current->lc;
    return current;
}
tree * tree_operation :: deletion(tree *t, int val)
{
    if(t == NULL)
        return t;
    if(val<t->data)
        t->lc=deletion(t->lc,val);
    else if(val>t->data)
        t->rc=deletion(t->rc,val);
    else
    {
        if(t->lc == NULL)
        {
            tree *temp=t->rc;
            delete t;
            return temp;
        }
        else if(t->rc == NULL)
        {
            tree *temp=t->lc;
            delete t;
            return temp;
        }
        tree *temp=minval(t->rc);
        t->data=temp->data;
        t->rc=deletion(t->rc,temp->data);
    }
    return t;
}
void tree_operation:: inorder(tree *t)
{
     if(t==NULL)
        return ;
    else
    {
        inorder(t->lc);
        cout<<"   "<<t->data;
        inorder(t->rc);
    }
}
void tree_operation :: postorder(tree *t)
{
    if(t==NULL)
        return ;
    else
      {
        postorder(t->lc);
        postorder(t->rc);
        cout<<"   "<<t->data;
      }
}
void tree_operation :: preorder(tree *t)
{
    if(t==NULL)
        return ;
    else
    {
        cout<<"   "<<t->data;
        postorder(t->lc);
        postorder(t->rc);
    }
}
int main()
{
    int n,a[20],b[20],i;
    bool f=false;
    int c=1,x;
    while(c!=0)
    {
        system("CLS");
        cout<<"\n\n\n                                                         =*=*=*=*=*What do you want*=*=*=*=*="<<endl;
        cout<<"\t\t 1. Sorting "<<endl;
        cout<<"\t\t 2. Searching"<<endl;
        cout<<"\t\t 3. Data structure"<<endl;
        cout<<"\t\t 4. Exit"<<endl;
        cout<<"\t\t Enter your choice"<<endl;
        cin>>c;
        int c1=1,c2=1,c3=1;
        if(c==1)
        {
            system("CLS");
            cout<<"                                                        ------Sorting with different Algorithms------";
            cout<<"\n\t\tEnter size: \n";
            cin>>n;
            for(i=0;i<n;i++)
            {
                cout<<"\t\tEnter value: ";
                cin>>a[i];
                b[i]=a[i];
            }
            while(c1!=0)
            {
                system("CLS");
                cout<<"\n                                             ------With whom you would like to proceed------"<<endl<<endl;
                cout<<"\t\t1.For bubble sort\n";
                cout<<"\t\t2.For insertion sort\n";
                cout<<"\t\t3.For selection sort\n";
                cout<<"\t\t4.For merge sort\n";
                cout<<"\t\t5.For radix sort\n";
                cout<<"\t\t6.For quick sort\n";
                cout<<"\t\t7.For heap sort\n";
                cout<<"\t\t8.For shell sort\n";
                cout<<"\t\t9.To exit\n";
                cout<<"\t\tEnter your choice\n";
                cin>>c1;
                if(c1==1)
                {
                    cout<<"\n\t\t Using Bubble Sort\n";
                     bubble(a,n);
                    cout<<"\n\t\tInput\n";
                     display(b,n);
                    cout<<"\n\t\tSorted array\n";
                     display(a,n);
                     reset(a,b,n);
                    cout<<"\n\t\t Press enter 1 to continue";
                    cin>>x;
                }
                else if(c1==2)
                {
                    cout<<"\n\t\t Using Insertion Sort\n";
                     insertion(a,n);
                    cout<<"\n\t\tInput\n";
                     display(b,n);
                    cout<<"\n\t\tSorted array\n";
                     display(a,n);
                     reset(a,b,n);
                    cout<<"\n\t\t Press enter 1 to continue";
                    int x;
                    cin>>x;
                }
                else if(c1==3)
                {
                    cout<<"\n\t\t Using Selection Sort\n";
                     selection(a,n);
                    cout<<"\n\t\tInput\n";
                     display(b,n);
                    cout<<"\n\t\tSorted array\n";
                     display(a,n);
                     reset(a,b,n);
                    cout<<"\n\t\t Press enter 1 to continue";
                    int x;
                    cin>>x;
                }
                else if(c1==4)
                {
                    cout<<"\n\t\t Using Merge Sort\n";
                    int l=0,u=n-1;
                     merge_Sort(a,l,u);
                    cout<<"\n\t\tInput\n";
                     display(b,n);
                    cout<<"\n\t\tSorted array\n";
                     display(a,n);
                     reset(a,b,n);
                    cout<<"\n\t\t Press enter 1 to continue";
                    int x;
                    cin>>x;
                }
                else if(c1==5)
                {
                     radix(a,n);
                    cout<<"\n\t\t Using Merge Sort\n";
                    cout<<"\n\t\tInput\n";
                     display(b,n);
                    cout<<"\n\t\tSorted array\n";
                     display(a,n);
                     reset(a,b,n);
                    cout<<"\n\t\t Press enter 1 to continue";
                    int x;
                    cin>>x;
                }
                else if(c1==6)
                {
                    cout<<"\n\t\t Using Quick Sort\n";
                     quick(a,0,n-1);
                    cout<<"\n\t\tInput\n";
                     display(b,n);
                    cout<<"\n\t\tSorted array\n";
                     display(a,n);
                     reset(a,b,n);
                    cout<<"\n\t\t Press enter 1 to continue";
                    int x;
                    cin>>x;
                }
                else if(c1==7)
                {
                    cout<<"\n\t\t Using Heap Sort\n";
                     heap(a,n);
                    cout<<"\n\t\tInput\n";
                     display(b,n);
                    cout<<"\n\t\tSorted array\n";
                     display(a,n);
                     reset(a,b,n);
                    cout<<"\n\t\t Press enter 1 to continue";
                    int x;
                    cin>>x;
                }
                else if(c1==8)
                {
                     shell(a,n);
                    cout<<"\n\t\t Using Shell Sort\n";
                    cout<<"\n\t\tInput\n";
                     display(b,n);
                    cout<<"\n\t\tSorted array\n";
                     display(a,n);
                     reset(a,b,n);
                    cout<<"\n\t\t Press enter 1 to continue";
                    int x;
                    cin>>x;
                }
                else if(c1==9)
                {
                    c1=0;
                }
            }
        }
        else if(c==2)
        {
            system("CLS");
            cout<<"\n\t\t\t                                          -------Searching with different Algorithms-----"<<endl;
            cout<<"\t\tEnter the size: \n";
            cin>>n;
            for(i=0;i<n;i++)
                {
                    cout<<"\t\tEnter the value: ";
                    cin>>a[i];
                }
            while(c2!=0)
            {
                system("CLS");
                cout<<"\n\n\t\t\t\t                              -------With whom you would like to go------"<<endl<<endl;
                cout<<"\t\t1. Linear Search"<<endl;
                cout<<"\t\t2. Binary Search"<<endl;
                cout<<"\t\t3. Ternary Search"<<endl;
                cout<<"\t\t4. Exit"<<endl;
                cout<<"\t\tEnter your choice"<<endl;
                cin>>c2;
                if(c2==1)
                {
                    cout<<"\t\tUsing Linear search"<<endl;
                    cout<<"\t\tEnter the number to be searched!!"<<endl;
                    cin>>x;
                    f=linear_search(a,n,x);
                    cout<<"\t\tFor the given array\n";
                    display(a,n);
                    if(f)
                        cout<<"\t\tGot your value!!"<<endl;
                    else
                        cout<<"\t\tTry again !!"<<endl;
                    cout<<"\n\t\t Press enter 1 to continue";
                    cin>>x;
                }
                else if(c2==2)
                {
                    cout<<"\t\tUsing Binary search"<<endl;
                    cout<<"\t\tEnter the number to be searched!!"<<endl;
                    cin>>x;
                    bubble(a,n);
                    f=binary_search(a,n,x);
                    cout<<"\t\tFor the given array\n";
                    display(a,n);
                    if(f)
                        cout<<"\t\tGot your value!!"<<endl;
                    else
                        cout<<"\t\tTry again !!"<<endl;
                    cout<<"\n\t\t Press enter 1 to continue";
                    cin>>x;
                }
                else if(c2==3)
                {
                   cout<<"\t\tUsing Ternary search"<<endl;
                    cout<<"\t\tEnter the number to be searched!!"<<endl;
                    cin>>x;
                    bubble(a,n);
                    f=ternary_search(0,n-1,x,a);
                    cout<<"\t\tFor the given array\n";
                    display(a,n);
                    if(f)
                        cout<<"\t\tGot your value!!"<<endl;
                    else
                        cout<<"\t\tTry again !!"<<endl;
                    cout<<"\n\t\t Press enter 1 to continue";
                    cin>>x;
                }
                else if(c2==4)
                    c2=0;
            }
        }
        else if(c==3)
        {
            while(c3!=0)
            {
                system("CLS");
                cout<<"\n                                                                   *+*+*+*+*+*+*Which Data Structure you want*+*+*+*+*+*+*"<<endl<<endl;
                cout<<"\t\t1.For stack array implementation\n";
                cout<<"\t\t2.For stack linked list \n";
                cout<<"\t\t3.For queue array implementation \n";
                cout<<"\t\t4.For queue linked list\n";
                cout<<"\t\t5.For double ended queue array implementation\n";
                cout<<"\t\t6.For double ended queue linked list\n";
                cout<<"\t\t7.For circular queue array implementation \n";
                cout<<"\t\t8.For circular queue linked list\n";
                cout<<"\t\t9.For double ended circular queue array implementation \n";
                cout<<"\t\t10.For double ended circular queue linked list\n";
                cout<<"\t\t11.For tree\n";
                cout<<"\t\t12.To exit\n";
                cout<<"\t\t Enter your choice\n";
                cin>>c3;
                if(c3==1)
                {
                    cout<<"\t\tEnter the size of array:\n";
                    cin>>x;
                    Stack s(x-1);
                    int c31=1;
                    while(c31!=0)
                    {
                        system("CLS");
                        cout<<"\n                                                                   *+*+*+*+*+*+*Which operation you want*+*+*+*+*+*+*"<<endl<<endl;
                        cout<<"\t\t1.To insert\n";
                        cout<<"\t\t2.To delete\n";
                        cout<<"\t\t3.Display\n";
                        cout<<"\t\t4.To exit\n";
                        cout<<"\t\tEnter your choice\n";
                        cin>>c31;
                        if(c31==1)
                        {
                            cout<<"\t\tEnter the value:\n";
                            cin>>n;
                            f=s.push(n);
                            if(f)
                                cout<<"\t\tValue added\n\n";
                            else
                                cout<<"\t\tValue cannot be added\n\n";
                            cout<<"\t\tPress enter 1 to continue:";
                            cin>>x;
                        }
                        else if(c31==2)
                        {
                            f=s.pop();
                             if(f)
                                cout<<"\t\tValue deleted\n\n";
                            else
                                cout<<"\t\tValue cannot be deleted\n\n";
                            cout<<"\t\tPress enter 1 to continue:";
                            cin>>x;
                        }
                        else if(c31==3)
                        {
                            s.print();
                            cout<<"\t\tPress enter 1 to continue:";
                            cin>>x;
                        }
                        else if(c31==4)
                        {
                            c31=0;
                        }
                    }
                }
                else if(c3==2)
                {
                    int c32=1;
                    stack_operation so;
                    while(c32!=0)
                    {
                        system("CLS");
                        cout<<"\n                                                                   *+*+*+*+*+*+*Which operation you want*+*+*+*+*+*+*"<<endl<<endl;
                        cout<<"\n\t\tStack-Web history\n";
                        cout<<"\t\t1.Jump forward\n";
                        cout<<"\t\t2.Current page\n";
                        cout<<"\t\t3.Jump back\n";
                        cout<<"\t\t4.Add new page\n";
                        cout<<"\t\t5.Display the pages linked\n";
                        cout<<"\t\t6.Exit\n";
                        cout<<"\t\tEnter your choice\n";
                        cin>>c32;
                    if(c32==1)
                    {
                        so.shifting(1);
                        cout<<"\t\tEnter 1 to continue\n";
                        cin>>x;
                    }
                    else if(c32==2)
                    {
                        so.shifting(0);
                        cout<<"\t\tEnter 1 to continue\n";
                        cin>>x;
                    }
                    else if(c32==3)
                    {
                        so.shifting(-1);
                        cout<<"\t\tEnter 1 to continue\n";
                        cin>>x;
                    }
                    else if(c32==4)
                    {
                        stack_linked *sl=new stack_linked();
                        cout<<"\t\tEnter the name of website"<<endl;
                        cin>>sl->name;
                        so.add(sl);
                        cout<<"\t\tEnter 1 to continue\n";
                        cin>>x;
                    }
                    else if(c32==5)
                    {
                        so.display();
                        cout<<"\t\tEnter 1 to continue\n";
                        cin>>x;
                    }
                    else if(c32==6)
                        c32=0;
                    }
                }
                else if(c3==3)
                {

                }
                else if(c3==4)
                {

                }
                else if(c3==5)
                {

                }
                else if(c3==6)
                {

                }
                else if(c3==7)
                {

                }
                else if(c3==8)
                {

                }
                else if(c3==9)
                {

                }
                else if(c3==10)
                {

                }
                else if(c3==11)
                {
                    int c311=1;
                    tree_operation t;
                    while(c311)
                    {
                        system("CLS");
                        cout<<"\n                                                +=+=+=+=+=+=+=What operation you want to do+=+=+=+=+=+=+=+"<<endl<<endl;
                        cout<<"\t\t1.To insert data"<<endl;
                        cout<<"\t\t2.To delete data"<<endl;
                        cout<<"\t\t3.To display elements in inorder way"<<endl;
                        cout<<"\t\t4.To display elements in preorder way"<<endl;
                        cout<<"\t\t5.To display elements in postorder way"<<endl;
                        cout<<"\t\t6.To exit"<<endl;
                        cout<<"\t\tEnter your choice"<<endl;
                        cin>>c311;
                        if(c311==1)
                        {
                            cout<<"\t\t Enter Data"<<endl;
                            cin>>c311;
                            t.root=t.insertion(t.root,c311);
                            cout<<"\t\tPress enter 1 to continue:";
                            cin>>x;
                        }
                        else if(c311==2)
                        {
                            cout<<"\t\t Enter data to be deleted"<<endl;
                            cin>>c311;
                            t.root=t.deletion(t.root,c311);
                            cout<<"\t\tPress enter 1 to continue:";
                            cin>>x;
                        }
                        else if(c311==3)
                        {
                            if(t.root!=NULL)
                            {
                                cout<<"\t\tElements in Inorder with root node "<<t.root->data<<endl;
                                t.inorder(t.root);
                                cout<<endl;
                            }
                            else
                                cout<<"\t\tTree is empty"<<endl;
                            cout<<"\t\tPress enter 1 to continue:";
                            cin>>x;
                        }
                        else if(c311==4)
                        {
                            if(t.root!=NULL)
                            {
                                cout<<"\t\tElements in preorder with root node "<<t.root->data<<endl;
                                t.preorder(t.root);
                                cout<<endl;
                            }
                            else
                                cout<<"\t\tTree is empty"<<endl;
                            cout<<"\t\tPress enter 1 to continue:";
                            cin>>x;
                        }
                        else if(c311==5)
                        {
                            if(t.root!=NULL)
                            {
                                cout<<"\t\tElements in postorder with root node "<<t.root->data<<endl;
                                t.postorder(t.root);
                                cout<<endl;
                            }
                            else
                                cout<<"\t\tTree is empty"<<endl;
                            cout<<"\t\tPress enter 1 to continue:";
                            cin>>x;
                        }
                        else
                            c311=0;
                    }
                }
                else if(c3==12)
                    c3=0;
            }

        }
        else if(c==4)
        {
            c=0;
        }
    }
    return 0;
}

