#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,d;
int a[N];
int e[N];
int dis[N][N];
int cnt[N][N]; 
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		e[i]=0;
		for(int j=1;j<=n;j++){
			dis[i][j]=0;
			cnt[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1;
	for(int i=1;i<=n;i++){
		while(abs(a[i]-a[l])>d){
			e[l]=i-1;
			l++;
		}
	}
	for(;l<=n;l++){
		e[l]=n;
	}
	for(int r=n;r>=1;r--){
		dis[r][r]=0;
		cnt[r][r]=1;
		for(int s=r-1;s>=1;s--){
			dis[s][r]=dis[min(e[s],r)][r]+1;
		}
	}
	for(int s=n;s>=1;s--)
		for(int r=s+1;r<=n;r++){
			cnt[s][r]=cnt[min(e[s],r)][r];
			if(min(e[s],r)-1>=s&&dis[min(e[s],r)-1][r]==dis[min(e[s],r)][r]){
				cnt[s][r]+=cnt[min(e[s],r)-1][r];
				if(min(e[s],r)-2>=s&&dis[min(e[s],r)-2][r]==dis[min(e[s],r)][r]){
					cnt[s][r]+=cnt[min(e[s],r)-2][r];
				}
			}
		}
	int ret=0;
	for(int i=1;i<=n;i++){
		e[i]=0;
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2){
				ret++;
			}
			cnt[i][j]=0;
			dis[i][j]=0;
		}
	}
	cout<<ret<<'\n';
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}

