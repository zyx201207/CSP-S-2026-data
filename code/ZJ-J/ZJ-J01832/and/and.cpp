#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],ans,b[N],t,k,g[N];
bool cmp(ll x,ll y)
{
	return x>y;
}
int pos(ll x)
{
	int l=1,r=40,ss=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(b[mid]>x)
		{
			ss=mid;
			r=mid-1;
		}
		else
		l=mid+1;
	}
	return ss;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	b[1]=1;
	for(int i=2;i<=40;i++)
	{
		b[i]=b[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int op=pos(a[1])-1,xx=1;
	while(xx<=n)
	{
		for(;xx<=n;xx++)
		{
			if(a[xx]>=b[op])
			g[++k]=a[xx];
			else
			break;
		}
		int len=0;
		for(int i=1;i<=k;i++)
		{
			if(g[i]>=b[op])
			len++;
		}
		if(len>=m)
		break;
		for(int i=1;i<=k;i++)
		{
			if(g[i]>=b[op])
			g[i]-=b[op];
		}
		op--;
	}
	sort(g+1,g+k+1,cmp);
	ans=g[1];
	for(int i=2;i<=m;i++)
	{
		ans&=g[i];
	}
	cout<<ans;
	return 0;
}
