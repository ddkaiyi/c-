#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
typedef struct Lnode{
    int data;
    struct Lnode *next;

}Lnode;

Lnode *Initlist(Lnode *head){
    head= new Lnode;
    cout<<"beginning"<<endl;
    head->next=NULL;
    return head;
};

Lnode *Createlist(Lnode *head,int n){
Lnode *r=head;
for(int i=0;i<n;i++){
Lnode *p=new Lnode;
cout<<"Insert data"<<endl;
cin>>p->data;
p->next=NULL;
r->next=p;
r=p;
   
}return head;
};

Lnode *Findkey(Lnode *head,int key){
    Lnode *p=head->next;
    while(p!=NULL&&p->data!=key)
        p=p->next;
    return p;
};

void Insertkey(Lnode *head,int key,int i){
    Lnode *p=head;
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!p||j>i-1) cout<<"ERROR"<<endl;
    Lnode *s= new Lnode;
    s->data=key;
   s->next= p->next;
   p->next=s;
   n++;
  cout<<"insert success"<<endl;


};

void deletekey(Lnode *head,int key){
    if(head->next==NULL){printf("empty list");return;}
    Lnode *p=head,*r;
    while(p&&p->data!=key){
        r=p;
        p=p->next;
    }
    if(p==NULL){cout<<"can't find"<<endl;return;}
    r->next=p->next;
    delete(p);
    n--;
    cout<<"delete success"<<endl;

}

int main()
{
    Lnode *head;
    head=Initlist(head);
    cin>>n;
    head=Createlist(head,n);
   Insertkey(head,1,2);
    // deletekey(head,1);
    Lnode *p=Findkey(head,1);
    if(p!=NULL) cout<<"find "<<endl;

  return 0;
}