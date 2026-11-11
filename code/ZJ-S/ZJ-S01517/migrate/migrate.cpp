#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000001;
ll n,d;
ll a[N];
ll dist[301][301];
int cnt[301][301];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		if(n<=300){
			memset(dist,0x3f,sizeof(dist));
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=n;i++)cin >> a[i];
			for(int i=1;i<=n;i++){
				int l=i;
				dist[i][i]=0;
				cnt[i][i]=1;
				for(int j=i+1;j<=n;j++){
					while(a[l]+d<a[j])l++;
					for(int k=j-1;k>=l;k--){
						if(dist[i][j]>dist[i][k]+1){
							dist[i][j]=dist[i][k]+1;
							cnt[i][j]=cnt[i][k];
						}
						else if(dist[i][j]==dist[i][k]+1)cnt[i][j]+=cnt[i][k];
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					//cout << cnt[i][j] << ' ';
					if(cnt[i][j]==2)ans++;
				}
				//cout << "\n";
			}
			cout << ans << "\n";
		}
	}
}
