#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,dd[15],ans=2e9;
bool cs[15],vv[15];
vector<int> mp[1000005];
queue<int> q;
void dfs(int dep){
	if(dep>k){
		int ltk=k;
		for(int i=1;i<=n;i++){
			if(!cs[i])continue;
			for(int j=0;j<mp[i].size();j++){
				if(mp[i][j]>i&&cs[mp[i][j]]){
					ltk--;
				}
			}
		}
		if(ltk>2)return;
		int res=0;
		for(int i=1;i<=n;i++){
			if(cs[i])continue;
			int ppp=2e18;
			for(int j=1;j<=n;j++)vv[j]=0,dd[j]=0;
			q.push(i);
			vv[i]=1;
			while(!q.empty()){
				int no=q.front();
				q.pop();
				for(int j=0;j<mp[no].size();j++){
					if(vv[mp[no][j]])continue;
					dd[mp[no][j]]=dd[no]+1;
					vv[mp[no][j]]=1;
					if(cs[mp[no][j]]){
						ppp=std::min(ppp,dd[mp[no][j]]);
						while(!q.empty())q.pop();
						break;
					}
					q.push(mp[no][j]);
				}
			}
			res=std::max(res,ppp);
		}
		ans=std::min(ans,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(cs[i])continue;
		cs[i]=1;
		dfs(dep+1);
		cs[i]=0;
		dfs(dep+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)mp[i].clear();
		ans=2e9;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
