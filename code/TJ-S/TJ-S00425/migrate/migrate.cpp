#include <iostream>
#define endl '\n'
using namespace std;
long long t,n,d,ans;
long long a[2000060];
long long f[2000060][2][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	cin>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i = 1;i <= n;i++)
			cin>>a[i];
		a[0] = -4*(1e18);
		a[n+1] = 4*(1e18);
		ans = 0;
		for(long long i = 1;i <= n+1;i++)
			f[i][0][0] = f[i][0][1] = f[i][1][0] = f[i][1][1] = 0;
		for(long long i = n;i >= 1;i--)
		{
			f[i][0][0] = 1;
			for(long long j = i+1;j <= n;j++)
			{
				if(a[j]-a[i] > d)
					break;
				if(a[j+1]-a[i] <= d)
					continue;
				if(j != i+1&&a[j-1]-a[i-1] > d)
					f[i][1][0]+=f[j][0][1];
				if(j != i+1&&a[j-1]-a[i-1] <= d&&(i == 1||a[j]-a[i-2] > d))
					f[i][1][1]+=f[j][0][1];
				if(a[j]-a[i-1] > d)
				{
					f[i][0][0]+=f[j][0][0];
					f[i][1][0]+=f[j][1][0];
				}
				if(a[j]-a[i-1] <= d&&(i == 1||a[j]-a[i-2] > d))
				{
					f[i][0][1]+=f[j][0][0];
					f[i][1][1]+=f[j][1][0];
				}
			}
		//cout<<"----------"<<i<<"----------"<<endl;
		//for(long long i = n;i >= 1;i--)
		//cout<<f[i][0][0]<<" "<<f[i][0][1]<<" "<<f[i][1][0]<<" "<<f[i][1][1]<<endl;
		}
		for(long long i = 1;i <= n;i++)
			ans+=f[i][1][0]+f[i][1][1];
		cout<<ans<<endl;
	}
	return 0;
}
//long long long long
//cin
