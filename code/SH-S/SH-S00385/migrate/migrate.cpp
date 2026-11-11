#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=309;
int c,T;
int n,d;
int x[N];
int dis[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=n+1;j++){
				dis[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			dis[i][i]=1;
		}
		int ans=0;
		for(int len=2;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				int mn=1e18,cnt=1;
				for(int k=l;k<r;k++){
					int t=x[r]-x[k];
					if(t<=d){
						if(mn==dis[l][k]+1){
							cnt++;
//							if(l==1&&r==5) cout<<k<<' ';
						}
						else if(mn>dis[k][r]+1){
							mn=dis[k][r]+1,cnt=1;
//							if(l==1&&r==5) cout<<k<<' ';
						}
					}
				}
//				cout<<l<<' '<<r<<' '<<cnt<<'\n';
				if(cnt==2) ans++;
				dis[l][r]=mn;
			}
		}
//		for(int l=1;l<=n;l++){
//			for(int r=l;r<=n;r++){
//				cout<<l<<' '<<r<<' '<<dis[l][r]<<'\n';
//			}
//		}
		cout<<ans<<'\n';
	}
	return 0;
}

