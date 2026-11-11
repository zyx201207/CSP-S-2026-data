#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,inf=3e18;
int csd,T,n,d,a[N],ans,b[5005],summ;
struct node{
	bool ok;
	int x;
}dp[305][305];
void dfs(int l,int r,int tt){
	if(tt>dp[l][r].x||summ>2) return;
	if(l==r){
		summ++;
		return;
	}
	for(int i=b[l];i>l;i--){
		if(i>r) i=r;
		dfs(i,r,tt+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>csd>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<305){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[i][j].x=inf;
					dp[i][j].ok=0;
				}
			}
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) b[i]=j;
					else break;
				}
			}
			for(int i=1;i<n;i++){
				if(a[i+1]-a[i]<=d) dp[i][i+1].ok=dp[i][i+1].x=1;
			}
			for(int len=3;len<=n;len++){
				for(int i=1;i<n;i++){
					int j=i+len-1;
					if(j>n) break;
					if(a[j]-a[i]<=d){
						dp[i][j].ok=dp[i][j].x=1;
						continue;
					}
					for(int k=i+1;k<j;k++){
						if(!dp[i][k].ok||!dp[k][j].ok) continue;
						dp[i][j].ok=1;
						if(dp[i][j].x>dp[i][k].x+dp[k][j].x){
							dp[i][j].x=dp[i][k].x+dp[k][j].x;
						}
					}
					summ=0;
					if(dp[i][j].ok) dfs(i,j,0);
					if(summ==2) ans++;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		
	}
	return 0;
}
