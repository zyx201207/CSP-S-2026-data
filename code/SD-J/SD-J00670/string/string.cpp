#include<bits/stdc++.h>
using namespace std;
long long n;
const int maxn=2e5+5;
const long long maxu=1e9+1;
long long sum[maxn];
char a[maxu];
char c[maxn];
long long cnt=1;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	sum[0]=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>sum[i]>>c[i];
		cnt+=sum[i];
		for(int j=cnt-sum[i];j<=cnt;j++)
		{
			a[j]=c[i];
		}
	}
	for(long long i=1;i<=(cnt-1)/2;i++)
	{
		if(a[i]!=a[cnt-i])
		{
			ans+=1;
		}
		else
		{
			ans+=0;
		}
	}
	cout<<ans;
	return 0;
} 
