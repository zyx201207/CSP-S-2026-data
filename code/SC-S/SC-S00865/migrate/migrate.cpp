#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=0x3f3f3f;
ll c,t,n,d,ans=0;
ll a[N];
ll f[N][N];
//开吃播吃爽了 
int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					f[i][j]=a[j]-a[i];
				}
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				ll b=0;
				ll ans1;
				if(f[i][j]!=0)
				{
					ans1=f[i][j];
					b++;
				}
				for(int k=i+1;k<j;k++)
				{
					if(f[i][k]+f[k][j]==ans1)
					{
						b++;
					}
					else if(f[i][k]+f[k][j]<ans1)
					{
						b=0;
						b++;
						ans1=f[i][k]+f[k][j];
					}
				}
				if(b==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//TM CCF NOJB!!!