#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,dp[310][310][310],x[2000010];
vector<pair<int,int> > ve;
inline bool ok(int i,int j){
	if(x[j]-x[i]<=d)return true;
	return false;
}
void dfs(int b,int x,int stp){
	dp[b][x][stp]++;
	for(int i=x+1;i<=n;i++){
		if(ok(x,i)){
			dfs(b,i,stp+1);
		}
	}
}
vector<int> avr;
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//freopen("migrate4.in","r",stdin);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			avr.clear();
			//memset(g,0x3f,sizeof(g));
			for(int i=1;i<=n;i++)cin>>x[i];
			int dk=x[2]-x[1];
			int ls=d/dk;
			for(int i=1;i<=ls;i++){
				avr.push_back(i);
			}avr.push_back(dk+dk-1);
			int ans=0;
			for(auto i:avr){
				ans+=n-i;
			}cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		//memset(g,0x3f,sizeof(g));
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
		}int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int k=0;
				for(k=1;k<=n;k++){
					if(dp[i][j][k]!=0)break;
				}if(dp[i][j][k]==2)ans++;
			}
		}cout<<ans<<'\n';
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
