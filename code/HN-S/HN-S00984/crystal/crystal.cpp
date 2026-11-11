#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500100;
int n,m;
int a[maxn],b[maxn],c[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i]-a[i-1];
		c[i]=c[i-1]+(b[i]-b[i-1])*(i-1);
		if(c[i]>m)
		{
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n;
	return 0;
 } 
