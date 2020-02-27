#include <stdio.h>
#include <cstdlib>
#include <iostream>

typedef struct node_type{
        int size;
        struct node_type* next;
        bool avail;
    }node;
    void alloc(node *ne){
        ne->avail= false;
    }

    int min=32;
    void printi(node * n){
        node * tptr=n;
        int i=1;
        while(tptr!=NULL){
            printf("%d-%d-%d\n",i,tptr->size,tptr->avail);
            tptr=tptr->next;
            i++;
        }
    }
    node * split(int a, node* ne){
        if(ne->size>min){
            node *temp = ne->next;
            node *newnode=(node*)malloc(sizeof(node));
            newnode->size=(ne->size/2);
            newnode->avail=true;
            newnode->next=NULL;
            ne->size=ne->size/2;
            ne->next=newnode;
            newnode->next=temp;
        }
        else
        if(a==1)
            return ne;
        else if(a==2)
            return ne->next;
    }
    node* del(node* dptr,node*ne){
        dptr->avail=1;
        int flag=1;
        node *prev=NULL;
        node *mptr=NULL;
        node *rptr=NULL;
        mptr=ne;
        int flagg=1;
        int buddy_count=1;
        while(mptr->next!=NULL&&flag==1){
            if(mptr==dptr){
                flag=0;
                mptr->avail=1;
            }
            else{
                if(mptr->size==dptr->size)
                    buddy_count++;
                else
                    buddy_count==1;
            prev=mptr;
            mptr=mptr->next;
            }
        }if(prev!=NULL) {
            if (buddy_count%2==0&&prev->size == mptr->size && prev->avail == true && mptr->avail == true) {
                prev->next = mptr->next;
                prev->size = prev->size * 2;
                rptr = prev;
                flagg = 0;
            } else if (buddy_count%2!=0&&mptr->next != NULL && mptr->size == mptr->next->size && mptr->avail == true &&
                       mptr->next->avail == true) {
                mptr->next = mptr->next->next;
                mptr->size = mptr->size * 2;
                rptr = mptr;
                flagg = 0;
            }
        }

        if(flagg==0){
            del(rptr,ne);
        }
        return rptr;
    }
    node * insert(int a, node* ne){
        node *temp=ne;
        node *tptr=ne;
        node * prev;
        node*tempe=tptr;
        int tempsize=1024;
        while(tptr!=NULL){
            if(tptr->size>=a&&tptr->avail== true&&tptr->size<=tempsize){
                tempe=tptr;
                tempsize=tptr->size;
            }
            prev=tptr;
            tptr=tptr->next;
        }
        tptr=tempe;
        if(tptr==NULL||tptr->avail==0)
            tptr=prev;
//        std::cout<<tptr->size;
        if(a<=tptr->size&&a>0&&tptr->avail== true){
            if(a>.5*tptr->size){
                alloc(tptr);
                return tptr;
            }
            if(a<=tptr->size&&tptr->size==min){
                alloc(tptr);
                return tptr;

            }
            if(a<=.5*tptr->size&&tptr->next!=NULL){
                temp=split(1,tptr);
                insert(a,temp);
            }
            if(a<=.5*tptr->size&&tptr->next==NULL){
                temp=split(2,tptr);
                insert(a,temp);
            }
        }

    }
    void dele(node *n){
        node * tptr=n;
        printi(tptr);
        int inde=1;
        printf("enter index to delete starting from 1");
        scanf("%d",&inde);
        tptr=n;
        if(inde>=1){
        while(inde>1){
            tptr=tptr->next;
            inde--;
        }
        printf("%d",inde);
        printf("%d%d",tptr->size,tptr->avail);
        if(tptr->avail=1){
        del(tptr,n);} else{printf("enter valid argument");}
        } else
            printf("enter valid index");
    }
    void inse(node *n){
        node * temp=n;
        int input=0;
        printf("enter size of memory to be allocated");
        scanf("%d",&input);
        if(input!=0){
            insert(input,temp);
        }
        else
            printf("enter valid ");
    }
    int main(void) {
        node* n;
        n=(node *)malloc(sizeof(node));
        n->size=1024;
        n->avail= true;
        n->next=NULL;
        int flag=1;
        while(flag){
            printf("Enter 1.Insert 2.Display 3.Delete 4.Exit");
            int input=0;
            scanf("%d",&input);
            if(input>0&&input<5){
                switch(input){
                    case 1:inse(n);break;
                    case 2:printi(n);break;
                    case 3:dele(n);break;
                    case 4:flag=0;
                }
            } else{
                printf("invalid entrt");
            }
        }

//        node * temp1=insert(32,n);
//        node * temp2=insert(64,n);
//        node* temp3=insert(60,n);
//        insert(150,n);
//        /*std::cout << temp->avail << std::endl;
//        std::cout << temp->size << std::endl;*/
//        del(temp2,n);
//        del(temp1,n);
//        insert(100,n);
//        insert(100,n);
//        while(n!=NULL){
//            std::cout << n->avail << std::endl;
//            std::cout << n->size << std::endl;
//            n=n->next;
//        }

    }




