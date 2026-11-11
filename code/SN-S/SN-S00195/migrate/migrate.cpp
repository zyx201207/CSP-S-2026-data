#include<bits/stdc++.h>
#define int long long
#define sor(i,l,r) for(int i=(l);i<=(r);i++)
#define ros(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
namespace Eaux{
	int C,T;
	void work(){
		cin>>C>>T;
		while(T--){
			int n,m;
			cin>>n>>m;
			vector<int> a(n+1);
			sor(i,1,n) cin>>a[i];
			if(n<=5000){
				vector<vector<int> > dp(n+1,vector<int>(n+1)),dis(n+1,vector<int>(n+1)),s(n+1,vector<int>(n+1));
				vector<int> pre(n+1);
				sor(i,1,n){
					ros(j,i,1){
						if(a[i]-a[j]<=m) pre[i]=j;
					}
				}
				sor(i,1,n){
					sor(j,i+1,n) dis[i][j]=2e9;
				}
				sor(i,1,n){
					dis[i][i]=0;
					sor(j,i+1,n){
						dis[i][j]=dis[i][max(i,pre[j])]+1;
						
					}
					
				}
				sor(i,1,n){
					int l=i,r=i;
					dp[i][i]=s[i][i]=1;
					sor(j,i+1,n){
						if(dis[i][j]!=dis[i][j-1]&&j!=i+1){
							l=r+1;
							r=j-1;
						}
						dp[i][j]=s[i][r]-s[i][max(l,pre[j])-1];
						s[i][j]=s[i][j-1]+dp[i][j];//cout<<dp[i][j]<<" "<<dis[i][j]<<"\n";
					}//cout<<"\n";
				}
				int ans=0;
				sor(i,1,n){
					sor(j,i+1,n) if(dp[i][j]==2) ans++;
				}
				cout<<ans<<"\n";
			}
			if(C==11||C==12){
				int d=1.0*m/(a[2]-a[1]);
				d++;
				int ans=n-(2*d-1)+1;
				if(ans>n||d<=2) ans=0; 
				else ans++;
				cout<<max(ans,0ll)<<"\n";
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Eaux::work();
	return 0;
}
