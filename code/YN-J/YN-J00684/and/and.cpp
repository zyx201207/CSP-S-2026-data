#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,e=1<<30-1;
int n,m,a[N],mx=INT_MIN,ans,flag;
struct node{
	int son[2],val;
}tr[N*4];
bool cmp(int a,int b)
{
	return a>b;
}
int check(int x)
{
	while(x)
	{
		if(!(x&1)) return 0;
		x>>=1;
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i],mx=max(mx,a[i]);
		if(check(a[i]))
		{
			flag=1;
		}
	}
	if(m==1)
	{
		cout<<mx<<'\n';
		return 0;
	}
	if(flag)
	{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans&=a[i];
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}