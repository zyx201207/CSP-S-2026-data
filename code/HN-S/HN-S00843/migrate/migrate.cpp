#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000100;
int c,t,n,mn=INT_MAX,cnt,ans;
ll d;
ll x[N];
vector<int> g[N];
void dfs(int u,int t,int dis){
	if(dis>mn) return;
	if(u==t){
		if(dis==mn) cnt++;
		else mn=dis,cnt=0;
		return;
	}
	for(auto v:g[u]){
		if(v>t) break;
		dfs(v,t,dis+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				cnt=0;
				mn=INT_MAX;
				dfs(i,j,0);
				ans+=(cnt==1);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
