#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],ans=0,fa[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) fa[i]=a[n]-a[i];
	for(long long i=1;i<=n;i++) s[i]=s[i-1]+fa[i];
	//for(int i=1;i<=n;i++) cout<<fa[i]<<"\n";
	long long int ans=0;
	if(n<=5000)
	{
		for(long long i=0;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				if(s[j]-s[i]-(j-i)*fa[j]<=m) ans=max(ans,j-i);
			}
		}
		cout<<ans;
	}
	else
	{
		for(long long i=n;i>=1;i--)
		{
			if(s[i]-i*fa[i]<=m) 
			{
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}
