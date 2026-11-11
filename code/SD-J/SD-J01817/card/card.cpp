#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N];
int cnt[M];//当前牌桌上i的位置
bool vis[M];//当前牌桌上是否有i 
int ans[M];//所求结果 
int x=0;//牌桌上牌的数量 
int qw[N];//i号牌是哪张 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(qw,0,sizeof(qw));
		memset(cnt,0,sizeof(cnt));
		x=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)//牌桌上没有a[j] 
			{
				vis[a[j]]=1;//放上去 
				x++;//数量加一 
				cnt[a[j]]=x;//a[j]的位置在末尾 
				qw[x]=a[j]; //末尾的位置是a[j] 
			}
			if(vis[a[j]]==1)//牌桌上有a[j] 
			{
				for(int k=cnt[a[j]]+1;k<=x;k++)
				{
					vis[qw[k]]=0;//拿走a[j]后面的牌 
				}
				x=cnt[a[j]];//更新牌桌上牌的数量 
			}
		}
		for(int j=1;j<=x;j++)
		{
			if(vis[qw[j]]==1&&cnt[qw[j]]<=x)
			{
				ans[qw[j]]++;//统计
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
