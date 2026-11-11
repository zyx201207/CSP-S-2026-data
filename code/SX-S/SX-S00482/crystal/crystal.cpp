#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N];
long long s2[N],s3[N];
long long mymax=-1,ans=0;
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000)
	{
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++) s2[i]=a[i]-a[1];
		for(int i=1;i<=n;i++) s3[i]=s3[i-1]+s2[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>i;j--)
			{
				long long x=(j-i)*s2[j]-(s3[j-1]-s3[i-1]);
				if(x<=m){
					ans=j-i+1;
					j=1;
				}
			}
			mymax=max(ans,mymax);
		}
		cout<<mymax;
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)
		{
			long long x=a[n]-a[i];
			if(x<=m)
			{
				ans++;
				m-=x;
			}
		}
		cout<<ans;
	}
	return 0;
}
