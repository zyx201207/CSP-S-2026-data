#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll a[200005];
struct node{
	int id,v;
}weight[200005];
bool cmp(node x,node y)
{
	return x.v>y.v;
}                                                                                                                                                                                                                                                                                                                                                           
int bit[35];
int can[35],t;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<=30;j++)
		{
			if(a[i]&(1ll<<j)) ++bit[j];
		}
	}
	for(int i=30;i>=0;i--)
	{
		if(bit[i]>=m) can[++t]=i;
	}
	for(int i=1;i<=n;i++)
	{
		weight[i].id=i;
		for(int j=1;j<=t;j++)
		{
			if(a[i]&(1<<can[j])) weight[i].v+=(1<<can[j]);
		}
	}
	
	sort(weight+1,weight+n+1,cmp);
	ll ans=(1ll<<31)-1;
	for(int i=1;i<=m;i++)
	{
		ans&=a[weight[i].id];
		//~ cout<<weight[i].id<<" ";
	}
	cout<<ans;
	return 0;
}
