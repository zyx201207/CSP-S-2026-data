#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)/2)
using namespace std;
const int N=5e5+5;
ll m,a[N],sum[N];
int n,ans=1;
int check(int x)
{
	int p=1,r=x;
	while(p!=0)
	{
		if(r<=p)
		{
			if(a[x]*x-sum[x]<=m)
				return 1;
			else
				p/=2;
		}
		if(a[x]*(x-(r-p)+1)-(sum[x]-sum[r-p-1])<=m)
			r-=p,p*=2;
		else
			p/=2;
	}
	return r;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
		ans=max(ans,i-check(i)+1);
	cout<<ans;
	return 0;
}

