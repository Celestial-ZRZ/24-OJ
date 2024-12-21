#include <iostream>
using namespace std;
#define BAD_TRAP cout<<"Hit bad trap at line "<<__LINE__<<endl,exit(1)


/*
TASK 1
Swap three numbers:
a<-b
b<-c
c<-a
 */
void swap3(int* a, int* b, int* c){
    int p=*a;
    *a=*b;
    *b=*c;
    *c=p;
}

/*
TASK 2
Given two integers a and b and a function pointer func (that takes two integers and returns an integer)
returns the result of applying func to a and b
*/
int perform(int a, int b, int (*func)(int,int)){
    return func(a,b);
}

/*
    TASK 3
    Allocate an int array of length len and return a pointer to the first element

    Your array should have : arr[i]=i
*/
int* get_array(int len){
    int *p=new int[len];
    for (int i=0;i<len;i++) p[i]=i;
    return p;
}

//remember to replace this with the correct type
#define TODO_WhatsTheTypeOfThis int*
/*
    TASK 4
    Given an integer array a. Set a[index]=value. Other values should be left unchanged.
*/
void setter(TODO_WhatsTheTypeOfThis a, int index, int value){
    a[index]=value;
}

struct Node{
    int val;
    Node* next;
};

/**
 * Task 5.1
 * 
 * Create a struct Node with value val and next pointer set to NULL(nullptr)
 */
Node* createNode(int val){
    Node *p=new Node;
    p->val=val;
    p->next=NULL;
    return p;
}

/**
 * Task 5.2
 * 
 * Given a Node* a and a Node* b, link a to b (aka. set a's next to b)
 */
void linkTo(Node* a, Node* b){
    a->next=b;
}

/*
DO NOT MODIFY
DO NOT MODIFY
DO NOT MODIFY
DO NOT MODIFY
DO NOT MODIFY
DO NOT MODIFY
*/

int add(int a, int b){
    return a+b;
}
int mul(int a, int b){
    return a*b;
}
int xors(int a, int b){
    return a^b;
}

int main(){
    int a=1,b=2,c=3;
    swap3(&a,&b,&c);
    if(a!=2 || b!=3 || c!=1){
        BAD_TRAP;
    }
    a=4,b=6,c=9;
    swap3(&a,&b,&c);
    if(a!=6 || b!=9 || c!=4){
        BAD_TRAP;
    }
    a=11,b=14,c=9;
    swap3(&a,&b,&c);
    if(a!=14 || b!=9 || c!=11){
        BAD_TRAP;
    }

    int res=perform(1,2,add);
    if(res!=3){
        BAD_TRAP;
    }
    res=perform(1,2,mul);
    if(res!=2){
        BAD_TRAP;
    }
    res=perform(114,514,xors);
    if(res!=624){
        BAD_TRAP;
    }

    int* arr=get_array(5);
    for(int i=0;i<5;i++){
        if(arr[i]!=i){
            BAD_TRAP;
        }
    }
    delete[] arr;


    arr=get_array(7);
    for(int i=0;i<7;i++){
        if(arr[i]!=i){
            BAD_TRAP;
        }
    }
    delete[] arr;

    int x[13];
    for(int i=0;i<13;i++){
        x[i]=i;
    }
    setter(x,5,100);
    for(int i=0;i<13;i++){
        if(i==5){
            if(x[5]!=100){
                BAD_TRAP;
            }
        }else{
            if(x[i]!=i){
                BAD_TRAP;
            }
        }
    }

    setter(x,7,99);
    for(int i=0;i<13;i++){
        if(i==5){
            if(x[5]!=100){
                BAD_TRAP;
            }
        }else if(i==7){
            if(x[7]!=99){
                BAD_TRAP;
            }
        }else{
            if(x[i]!=i){
                BAD_TRAP;
            }
        }
    }

    {
        Node* a=createNode(1);
        Node* b=createNode(2);
        Node* c=createNode(3);
        linkTo(a,b);
        if(a->val!=1 || a->next!=b || b->val!=2 || b->next!=NULL || c->val!=3 || c->next!=NULL){
            BAD_TRAP;
        }
    }

    cout<<"All tests passed"<<endl;
    return 0;
}