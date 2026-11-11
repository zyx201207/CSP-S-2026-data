#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+500;
int flaga=1;
struct node
{
	int num,x;
}a[N];
int n,m,cnt,d[N],ans,vis[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1].x;
	a[1].num=1;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	int x;
	cin>>x;
	if(x!=a[1].x) flaga=0,a[2].x=x,a[2].num=1;
	else a[1].num++;
	for(int i=3;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x!=a[cnt].x) a[++cnt].x=x,a[cnt].num=1;
		else a[cnt].num++;
		if(x-a[cnt].x!=a[cnt].x-a[cnt-1].x) flaga=0;
	}
	if(cnt==1)
	{
		cout<<n;
		return 0;
	}
	if(flaga)
	{
		int t=a[2].x-a[1].x,c=1,p=a[2].x-a[1].x;
		if(m<t)
		{
			cout<<c;
			return 0;
		}
		while(m>=t)
		{
			m-=t;
			t+=p;
			c++;
		}
		cout<<c;
	}
	return 0;
}