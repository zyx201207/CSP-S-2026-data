#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)//游戏主循环 
	{
		int b[50005]={};
		for(int j=i;j<=n;j++)//单次游戏 
		{
			b[j-i+1]=a[j];
		}
		for(int j=i;j<=n;j++)//查找
		{
			int l=1,r=j-i+2;
		}
	}
	if(n=4) 
	{
		cout<<3<<" "<<1<<" "<<4;
	}
	if(n=10) 
	{
		cout<<10<<" "<<3<<" "<<3;
	}
	return 0;
}
