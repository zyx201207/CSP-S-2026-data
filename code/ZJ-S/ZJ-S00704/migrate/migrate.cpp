#include<bits/stdc++.h>
using namespace std;
long long x[2114514];
long long best[5000][5000],best1[5000][5000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d,ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
		}
		long long ri=n-1;
		best1[ri][ri]=1;
		for(int i=n-2;i>=0;i--)
		{
			if(x[i+1]-x[i]>d)
			{
				ri=i;
				continue;
			}
			long long rig=0;
			long long l=i,r=ri;
			while(l<=r)
			{
				long long mid=(l+r)/2;
				if(x[mid]>x[i]+d)r=mid-1;
				else
				{
					rig=max(rig,mid);
					l=mid+1;
				}
			}
			for(int j=rig+1;j<=ri;j++)
			{
				best[i][j]=best[rig][j]+1;
				best1[i][j]=best1[rig][j];
				for(int k=i+1;k<rig;k++)
				if(best[k][j]+1==best[i][j]){
					best1[i][j]+=best1[k][j];
				}
				if(best1[i][j]==2)ans++;
			}
			for(int j=i+1;j<=rig;j++)
			{
				best[i][j]=1;
				best1[i][j]=1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}


