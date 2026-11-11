#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
int n,d;
int dis[N][N],cnt[N][N];
int a[N];
void S( ){
	cin>>n>>d;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=2e18+10,cnt[i][j]=0;
	for(int i=1;i<=n;i++) cin>>a[i],dis[i][i]=0,cnt[i][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(abs(a[i]-a[j])<=d){
				dis[i][j]=1;
				cnt[i][j]=1;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(k==i||k==j||i==j) continue;
				if((dis[i][k]+dis[k][j])<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
					if(cnt[i][j]>2) cnt[i][j]=3;
				}
				else if((dis[i][k]+dis[k][j])==dis[i][j]){
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
					if(cnt[i][j]>2) cnt[i][j]=3;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(cnt[i][j]==2) ans++;
	cout<<ans<<endl;
}
int c,T;
signed main( ){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--) S( );
}
