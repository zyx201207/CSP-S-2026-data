#include<bits/stdc++.h>
#define int long long
using namespace std;
int x1[500005];
int f[505][505];
int cnt[505][505];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;cin>>c>>t;
	while(t--)
	{
		memset(f,0x3f,sizeof(f));int ans=0;
		int n,d;
		cin>>n>>d;	
		for(int i=1;i<=n;i++)
		{
			cin>>x1[i];
			f[i][i]=0;
		}
		sort(x1+1,x1+1+n);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x1[j]-x1[i]<=d){
					f[i][j]=0;
					f[j][i]=0;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++){
					if(f[i][j]>f[i][k]+f[k][j]+1){
						f[i][j]=f[i][k]+f[k][j]+1;
						cnt[i][j]=1;
					}
					else if(f[i][j]==f[i][k]+f[k][j]+1){
						cnt[i][j]++;
					}
				}
			}
		}
		//cout<<f[1][4]<<"\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++){
				if(f[i][j]==0){
					continue;
				}
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n"; 
	} 
	return 0; 
}
