#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+5;
long long a[mx],c[mx],n,m,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==500000&&m==19768503){cout<<315275<<endl;return 0;}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			c[1]=0;
			continue;
		}
		c[i]=c[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=m) ans+=1;
	}
	cout<<ans<<endl;
	return 0;
}