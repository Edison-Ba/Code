#include<iostream>
using namespace std;//2939638431
int n;
void LHS(int a) {
	cout<<"��ǰ�е�"<<a<<"��ɽ��ɽ���е�"<<a<<"���������е�"<<a<<"���Ϻ��и���"<<a<<"��С���н���"<<a<<"������:	";
	if(a>=n){
		cout<<"���½�����,����"<<n<<"��ɽ"; 
		return;
	}
	return LHS(a+1);
}
int main() {
	cin>>n;
	LHS(1);
	return 0;
}
