#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+8;
long long c,t,n,d;
long long cnt[MAXN][MAXN],dis[MAXN][MAXN];
long long a[MAXN],ans;
inline long long abs_(long long x) { return x<0 ? -x:x; }
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		memset(cnt,0,sizeof(cnt));
		memset(dis,0,sizeof(dis));
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=1;j<i;j++) 
				if(abs_(a[i]-a[j])<=d) 
					cnt[j][i]=dis[j][i]=1;
		}
		for(int i=1;i<=n;i++)
			for(int k=i+1;k<=n;k++)
				for(int j=k+1;j<=n;j++)
				{
					if(!dis[i][j]&&dis[i][k]&&dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
					else if(dis[i][k]&&dis[k][j]&&dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
		for(int i=1;i<=n;i++) 
			for(int j=i+1;j<=n;j++) 
				if(cnt[i][j]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}

