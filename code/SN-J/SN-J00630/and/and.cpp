#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int xx[35];
ll a[N],b[N]; 
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		a[i]=x;
		int cnt=0;
		while(x)
		{
			cnt++; 
			if(x&1)  xx[cnt-1]++;  
			x>>=1;
		}
		maxn=max(maxn,cnt-1);
	}
	int ans=-1;
	for(int i=maxn;i>=0;i--)
		if(xx[i]>=m)
		{
			ans=i;
			break;
		}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&(1<<ans))  b[++cnt]=a[i];
	}
	sort(b+1,b+cnt+1,cmp);
	int maxx=b[1];
	for(int i=1;i<=m;i++)  maxx=(b[i] & maxx);
	cout<<maxx;
}
//zen'me'hai'shi'ge'zha'pian'ti'huai'huai
