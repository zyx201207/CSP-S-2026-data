#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,tt,n,d,cnt,len,des;
vector<int> g[5005];
void dfs(int cur,int ll){
	if(ll==len+1){
		if(cur==des) ++cnt;
		return;
	}
	for(int i=cur;i<=des;++i){
		dfs(i,ll+1);
	}
}
int dp[5005][5005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>tt;
	while(tt--){
		cin>>n>>d;
		cnt=0;
		int ans=0;
		vector<int> x(5005);
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(llabs(x[i]-x[j])<=d) {
					g[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=5003;++i){
			for(int j=1;j<=5003;++j){
				dp[i][j]=0x3f3f3f3f3f3f3f;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(llabs(x[i]-x[j])<=d){
					dp[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1+i;j<=n;++j){
				len=dp[i][j];
				des=j;cnt=0;
				dfs(i,0);
				if(cnt==2) ++ans;
			}
		}
		cout<<ans<<'\n';
	}	
	
	return 0;
}
