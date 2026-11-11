#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10,M=3e2+10,inf=1e18;
int c,t,n,d,x[N],dis[M][M],cnt[M][M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=inf;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					dis[i][j]=dis[j][i]=cnt[i][j]=cnt[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					int val=dis[j][i]+dis[i][k];
					if(dis[j][k]>val){
						dis[j][k]=val;
						cnt[j][k]=cnt[j][i]*cnt[i][k];
					}
					else if(dis[j][k]==val)cnt[j][k]+=cnt[j][i]*cnt[i][k];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
