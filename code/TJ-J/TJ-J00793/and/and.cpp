#include<bits/stdc++.h>
using namespace std;
long long const MAXN=2e5+5;
long long n,m,a[MAXN],maxn=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	if(m==2)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>maxn) maxn=(a[i]&a[j]);
			}
		}
	}
	else if(m==1)
	{
		for(long long i=1;i<=n;i++)
		{
			if((a[i]&1)>maxn) maxn=(a[i]&1);
		}
	}
	cout<<maxn;
	return 0;
}
