#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
int c,n,d;
int a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>c>>T;
	while(T--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int ii=1;ii<=n;ii++)
		{
			int res=0,cnt=1,bj=ii,i=ii;
			for(int k=i+1;k<=n;k++)
			{
				if(a[k]-a[i]>d)
					break;
				if(a[k]-a[i]<=d)
				{
					res++;
					if(res==2&&a[k+1]-a[i]>d&&a[k+1]-a[bj]<=d)
					{
						ans+=cnt;
						i=bj;
						res=0;
						cnt++;
					}
					else
					{
						bj=k;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

