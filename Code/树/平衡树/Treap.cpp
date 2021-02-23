#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map> 
using namespace std;
struct ND{
	int l;
	int r;
	int fa;
	int val;
	int rval;
	int siz;
	int ct;
}a[100005];
int n;
int k;
int Do;
int cnt=0;
void tl(int x){//�Ҷ����� 
	int son=a[x].r;
	a[x].r=a[son].l;
	a[son].l=x;
	a[son].fa=a[x].fa;
	a[x].fa=son;
	a[son].siz=a[x].siz;
	a[x].siz=a[a[x].l].siz+a[a[x].r].siz+a[x].ct; 
	return;
}
void tr(int x){//������� 
	int son=a[x].l;
	a[x].l=a[son].r;
	a[son].r=x;
	a[son].fa=a[x].fa;
	a[x].fa=son;
	a[son].siz=a[x].siz;
	a[x].siz=a[a[x].l].siz+a[a[x].r].siz+a[x].ct; 
	return;
}
int root(){
	int x=1;
	while(a[x].fa>0){
		x=a[x].fa;
	}
	return x;
}
void udt(int x){
	int now=x;
	while(a[x].fa>0){
		a[x].siz=a[a[x].l].siz+a[a[x].r].siz+a[x].ct; 
	}
	return 0;
}
int in(int v){
	int now=root();
	while(now>0){
		if(v==a[now].siz){//�ظ�Ԫ�� 
			a[now].ct++;
			a[now].siz++;
			udt(now);
			return now;
		}
		if(v<a[now].siz){//������ 
			if(a[now].l){
				now=a[now].l;
			}
			else{
				cnt++;
				a[now].l=cnt;
				a[cnt].fa=now;
				a[cnt].siz=1;
				a[cnt].ct=1;
				a[cnt].val=v;
				a[cnt].rval=rand()*rand();
				now=cnt;
				udt(now);
				break;
			}
		}
		else{//������ 
			if(a[now].r){
				now=a[now].r;
			}
			else{
				cnt++;
				a[now].r=cnt;
				a[cnt].fa=now;
				a[cnt].siz=1;
				a[cnt].ct=1;
				a[cnt].val=v;
				a[cnt].rval=rand()*rand();
				now=cnt;
				udt(now);
				break;
			}
		}
	}
	while(a[now].rval<a[a[now].fa].rval){//��֤С���� 
		if(now==a[a[now].fa].l){
			tr(a[now].fa);
		}
		else{
			tl(a[now].fa);
		}
	}
	return now;
}
void del(int v){
	int now=root();
	while(now>0){
		if(a[now].val==v){//ɾ�� 
			if(a[now].ct>1){
				a[now].ct--;
				a[now].siz--;
				udt(now);
				return
			}
			else{
				while((a[now].l>0)&&(a[now].r>0)){//������ 
					if(a[a[now].l].rval>a[a[now].r].rval){//���ӵ��� 
						tl(now); 
					}
					else{
						tr(now);
					}
				}
				if((a[now].l<=0)||(a[now].r<=0)){//Ҷ 
					if(now==a[a[now].fa].l){//����� 
						a[a[now].fa].l=0;
					}
					else{//�Ҷ� 
						a[a[now].fa].r=0;
					}
					udt(a[now].fa);
				}
				else{
					int son=max(a[now].l,a[now].r);//���� 
					if(now==a[a[now].fa].l){//����� 
						a[a[now].fa].l=son;
						a[son].fa=a[now].fa;
					}
					else{//�Ҷ� 
						a[a[now].fa].r=son;
						a[son].fa=a[now].fa;
					}
					udt(a[now].fa);
				}
			}
		}
		if(a[now].val<v){
			now=a[now].l;
		}
		else{
			now=a[now].r;
		}
	}
	return;
}
int findx(int x){
	int now=root(),le=x+1;//���ǿ�ʼ��-INF 
	while(now>0){
		if(le<=a[a[now].l].siz){//������ 
			now=a[now].l;
		}
		if(le>a[a[now].l].siz){//���������� 
			if(le<=a[a[now].l]+a[now].ct){//���ǵ�ǰ�ڵ� 
				return a[now].val;
			}
			else{//������ 
				le-=a[now].ct;
				le-=a[a[now].l].siz;
				now=a[now].r; 
			}
		}
	}
	return -1;
}
int findv(int v){
	int now=root();
	int rk=0;//����-INF 
	while(now>0){
		if(v==a[now].val){//�ҵ� 
			rk+=a[a[now].l].siz;
			return rk;
		}
		if(v>a[now].val){//������ 
			rk+=a[now].ct;
			rk+=a[a[now].l].siz;
			now=a[now].r; 
		}
		else{//������ 
			now=a[now].l; 
		}
	}
	return rk;
}
int bf(int v){//ǰ�� 
	int now=root(),Min=1/*-INF*/;
	while(now>0){
		if(a[now].val==v){//�ҵ��� 
			if(a[now].l>0){//�������� 
				now=a[now].l;
				while(a[now].r>0){//���������ֵ 
					now=a[now].r;
				}
				return now;
			}
			else{
				if(now==a[a[now].fa].r){//���Ҷ� 
					return a[now].fa; 
				} 
			}
		}
	}
	return -1;
}
int af(int v){//��� 
	return -1;
}
int main(){
	cin>>n;
	in(-0x3f3f3f3f);
	in(0x3f3f3f3f);
	srand(n);
	for(int i=1;i<=n;i++){
		cin>>Do>>k;
		if(Do==1){
			in(k);
		}
		if(Do==2){
			del(k);
		}
		if(Do==3){
			cout<<findv(k)<<endl;
		}
		if(Do==4){
			cout<<findx(k)<<endl;
		}
		if(Do==5){
			cout<<bf(k)<<endl;
		}
		if(Do==6){
			cout<<af(k)<<endl;
		}
	}
	return 0;
}
