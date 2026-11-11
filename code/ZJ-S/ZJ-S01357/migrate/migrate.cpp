#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000010],dist[1000][1000],dp[2000010],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c>=1&&c<=10){
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			memset(dist,0x3f,sizeof dist);
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++) dist[i][j]=1,dist[j][i]=1;
			for(int i=1;i<=n;i++) dist[i][i]=0;
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			for(int i=1;i<=n;i++){
				memset(dp,0,sizeof dp);
				dp[i]=1;
				for(int j=i+1;j<=n;j++){
					for(int k=i;k<j;k++)
						if(dist[i][k]+1==dist[i][j]&&dist[k][j]==1) dp[j]+=dp[k];
					if(dp[j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
				int r=lower_bound(a+1,a+n+1,a[i]+d+1)-a-1;
				if(r==n) break;
				int j=r+1,v;
				while(r-(v=upper_bound(a+1,a+n+1,a[j]-d)-a-1)>=1&&j<=n){
					if(r-v==1) ans++;
					j++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}

//s 1= please
//The day before csp-s2,I km a super bubble and craft a ultra totem!!
//If I don't have s 1=,I will AFO soon.....too sad
//luogu account:sadtime