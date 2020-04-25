#include<iostream>
using namespace std;
//bai tập về queue
struct node{
	int data;
	struct node *pNext;

};
typedef node Node;
struct queue{
	Node *pHead;
	Node *pTail;
	int count;
};
typedef queue Queue;

void KhoiTao(Queue &q){
	q.pHead=NULL;
	q.pTail=NULL;
}
Node *KhoiTaoNode(int x){
	Node *p=new Node;
	p->data=x;
	p->pNext=NULL;
}
//rong return 1
int IsEmpty(Queue q){
	if(q.pHead==NULL){
		return 1;
	}
	return 0;
}
//them cuoi = PUSH
bool ThemCuoi(Queue &q,int x){
	Node *p=new Node;
	p=KhoiTaoNode(x);
	if(IsEmpty(q)==1){
		q.pHead=p;
		q.pTail=p;
		q.count=1;
	}
	else{
		q.pTail->pNext=p;
		q.pTail=p;
		q.count++;
	}
}
void Xuat(Queue q){
	if(q.pHead!=NULL){
		cout<<q.pHead->data<<"\t";
		q.pHead=q.pHead->pNext;
		Xuat(q);
	}	
}
void xoaCuoi(Queue &q){
	if(IsEmpty(q)==1){
		cout<<"\n khong co gi de xoa :";
	}
	else{
		if(q.count==1){
			KhoiTao(q);
		}
		else{
			Queue q1;
			KhoiTao(q1);
			int tam=0;
			for(Node *i=q.pHead;i!=NULL;i=i->pNext){
				tam++;
				if(tam>q.count-1){
					break;
				}
				ThemCuoi(q1,i->data);
				
			}
			KhoiTao(q);
			for(Node *j=q1.pHead;j!=NULL;j=j->pNext){
				ThemCuoi(q,j->data);
			}
		}
	}
}
bool Pop(Queue &q,int &x){
	if(IsEmpty(q)==1){
		return 0;
	}
	else{
		x=q.pHead->data;
		Node *i=q.pHead;
		q.pHead=q.pHead->pNext;
		delete i;
	}
}
//xoa bat ki 
void xoaBatKi(Queue &q){
	if(IsEmpty(q)==1){
		cout<<"\n queue rong !!";
	}
	else{
		int vitri;
		cout<<"\n nhap vitri xoa :";
		cin>>vitri;	
		
		if(vitri==1){
			int x;
			Pop(q,x);
		}
		else{
			Queue q1;
			KhoiTao(q1);
			int tam=0;
			for(Node *i=q.pHead;i!=NULL;i=i->pNext){
				tam++;
				if(tam==vitri){
					continue;
				}
				else{
					ThemCuoi(q1,i->data);
				}
			}
			KhoiTao(q);
			for(Node *j=q1.pHead;j!=NULL;j=j->pNext){
				ThemCuoi(q,j->data);
			}
			KhoiTao(q1);
		}
	}
}
void themBatKi(Queue &q){
	int x;
	int vitri;
	cout<<"\n nhap data :";
	cin>>x;
	cout<<"\n nhap vi tri them :";
	cin>>vitri;
	if(IsEmpty(q)==1){
		ThemCuoi(q,x);
	}
	else{
		Queue q1;
		KhoiTao(q1);
		int tam=0;
		for(Node *i=q.pHead;i!=NULL;i=i->pNext){
			tam++;
			if(tam==vitri){
				ThemCuoi(q1,i->data);
				ThemCuoi(q1,x);
			}
			else{
				ThemCuoi(q1,i->data);
			}
		}
		KhoiTao(q);
		for(Node *j=q1.pHead;j!=NULL;j=j->pNext){
			ThemCuoi(q,j->data);
		}
	}
}
int main(){
	Queue q;
	KhoiTao(q);
	ThemCuoi(q,1);
	ThemCuoi(q,2);
	ThemCuoi(q,3);
	ThemCuoi(q,4);
	ThemCuoi(q,5);
//	xoaCuoi(q);
//	xoaBatKi(q);
	themBatKi(q);
	Xuat(q);
}









