#include <bits/stdc++.h>

using namespace std;
int m[100005];
int N,M;

bool check(int x)
{
	int sum=0;
	int cnt=0;//��cntģ��ɷָ���
	for(int i=1;i<=N;i++)
	{
		sum+=m[i];//һֱ����̰��
		if(sum>x)//�����mid���Ǵ�ʱ��������Ͳ��ܼ����ˣ�ǰ�����ĺ;��Ǳ�midС����������
		{
			cnt++;//��һ���ָ���
			sum=m[i];//sumҪ���¿�ʼ
		}
	}
	return cnt<=M-1;//������ǵ�Ҫ������ʱ����Ҫ�ķָ��߾������� 
					//���ǵ�cntС��M-1ʱ��˵����ʱ�ķַ����������Ž⣬���ܰ������ַַ��������·֣����Է���true
					//���cnt>M-1 �Ǿ͸����ⲻһ���ˣ�ֱ�ӷ���false
} 

int main()
{
	freopen("data.in","r",stdin);
	freopen("thestd.out","w",stdout);
	cin>>N>>M;
	int l=0;
	int r=0;
	for(int i=1;i<=N;i++)
	{
		cin>>m[i];
		l=max(l,m[i]);//��������ȷ����������� �������ȷ�����ǿ��԰�l��ʼ����1����r��ʼ����һ���Ƚϴ����
		r+=m[i];
	}	
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	return 0;
}
