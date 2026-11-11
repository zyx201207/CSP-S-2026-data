#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn],sum[maxn],d[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	//cout<<endl;
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++) 
	{
		for(int j=i;j<=n;j++)
		{
			d[++cnt]=a[j]*(j-i+1)-sum[j]+sum[i-1];
			if(d[cnt]<=m)
			{
				//cout<<i<<' '<<j<<endl;
				ans=max(ans,j-i+1);
			}
		}
	}
//	for(int i=1;i<=cnt;i++) cout<<d[i]<<' ';
	cout<<ans;
	return 0;
} 