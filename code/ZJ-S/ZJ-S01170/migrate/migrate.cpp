#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e5+5;
const int M=5e3+5;
const int INF=0x3f3f3f3f3f3f3f3f;

int c,t;

int n,d;

int a[N];

int dp[M][M];
int f[M][M];

void solve1(){
	
	while(t--){
		
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=-1;
				f[i][j]=0;
			}
		}
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					dp[i][j]=1;
					f[i][j]=1;
				}
			}
		}
		
		int ans=0;
		
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				for(int k=i+1;k<j;k++){
					if(dp[i][k]!=-1&&dp[k][j]!=-1){
						int cnt=dp[i][k]+dp[k][j];
						int cnt2=min(3ll,f[i][k]*f[k][j]);
						if(dp[i][j]==-1){
							dp[i][j]=cnt;
							f[i][j]=cnt2;
						}else if(dp[i][j]==cnt){
							f[i][j]=min(3ll,f[i][j]+cnt2);
						}else if(dp[i][j]>cnt){
							dp[i][j]=cnt;
							f[i][j]=cnt2;
						}
					}
				}
				if(f[i][j]==2) ans++;
//				cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
			}
		}
		
		cout<<ans<<"\n";
		
	}
	
	return;
}

int lst[N];
int vis[N];

void solve2(){
	
	while(t--){
		
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d){
					lst[i]=j;
				}else break;
			}
//			cout<<lst[i]<<" ";
		}
		
		int ans=0;
		
		for(int i=1;i<=n;i++){
			for(int j=i,nxt=i,c=0;j<=n;j++){
				vis[nxt+1]++;
				vis[lst[j]+1]--;
				if(j==nxt) nxt=lst[j];
				c+=vis[j];
				if(c==2) ans++;
			}
			for(int j=1;j<=n;j++){
				vis[j]=0;
			}
		}
		
		cout<<ans<<"\n";
		
	}
	
	return;
}

signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>t;
	
	if(c<=6){
		solve1();
	}else{
		solve2();
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/