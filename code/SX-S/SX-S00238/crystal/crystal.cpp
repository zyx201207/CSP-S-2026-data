#include<bits/stdc++.h>
using namespace std;
const int X=5e5+5;
long long n,m,a[X],b[X],ans,k=1;
bool flag=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long k=a[2]-a[1];
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=k) flag=0;
	if(flag)
	{
		int tot=0;
		for(int i=1;i<=n;i++) if(m-i*k>=0) m-=i*k,tot++;
		cout<<tot+1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++) if(a[i]*i-b[i]<=m) ans=max(ans,(long long)i);
	for(int i=n-1;i>=1;i++) 
	{
		if(a[n]*k-(b[n]-b[i-1])>m)
		{
			ans=max(ans,k);
			break;
		 } 
		k++;
	}
	cout<<ans;
	return 0;
}
