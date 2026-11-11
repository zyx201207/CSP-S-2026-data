#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
long long a[MAXN];
bool pir[MAXN];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c;
	if(c==11 or c==12)
	{
		int t;
		cin>>t;
		for(int i=0;i<t;i++)
		{
			long long n,m;
			cin>>n>>m;
			for(int j=0;j<n;j++)
			{
				cin>>a[j];
			}
			long long cha=a[2]-a[1];
			long long dist=m/cha;
			if(dist==1)
			{
				cout<<0;
				return 0;
			}
			int now=2*dist-1;
			fill(pir,pir+n,0);
			while(now<=n-1)
			{
				pir[now]=1;
				now+=dist;
			}
			long long ans=0;
			for(int i=1;i<n;i++)
			{
				ans+=pir[i]*n-i;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
