#include<bits/stdc++.h>
using namespace std;
vector<long long>x,far[2000001];
double s[1][2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			s[0][i]=s[0][i-1]+x[i];
			for(int j=i-1;j>0;j--)
			{
				if(ceil(1.0*(s[0][i]-s[0][j])/d)>(i-j))break;
				else far[j][i]=ceil(1.0*(s[0][i]-s[0][j])/d);
			}
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int cnt=0;
				if(far[i][j]==0)break;
				if(far[i][j]==1)continue;
				for(int k=1;k<j;k++)
				{
					if(far[i][k]+far[k][j]==far[i][j])cnt++;
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
