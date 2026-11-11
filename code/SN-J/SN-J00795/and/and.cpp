//姓名：高梓宸    学校：西安辅轮中学      SN-J00795 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	int st[200005]={},top=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		st[top++]=a;
	}
	for(int i=0;i<top;i++)
	{
		for(int j=i;j<top;j++)
		{
			if(st[j]>=st[j-1])
			{
				swap(st[j],st[j-1]);
			}
		}
	}
	cout<<st[m-1];
	return 0;
}
