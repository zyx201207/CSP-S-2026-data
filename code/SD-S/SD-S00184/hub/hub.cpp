#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,t,n,k,u,v,vis[N],viss[N],b[N];
vector <int> ve[N];
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++) ve[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		ve[u-1].push_back(v-1);
		ve[v-1].push_back(u-1);
	}
	int ans=1e18;
	for(int bit=0;bit<(1<<n);bit++){
		for(int i=0;i<n;i++) vis[i]=viss[i]=b[i]=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(bit&(1<<i)) cnt++,vis[i]=1; 
		}
		if(k!=cnt) continue;
		int cntt=0;
		for(int i=0;i<n;i++){
			if(vis[i]&&!viss[i]){
				viss[i]=1;
				cntt++;
				queue <int> q;
				q.push(i);
				while(!q.empty()){
					int h=q.front();
					q.pop();
					for(int v:ve[h]){
						if(vis[v]&&!viss[v]){
							viss[v]=1;
							q.push(v);
						}
					}
				}
			}
		}
		if(cntt>2) continue;
		int mx=0;
		for(int i=0;i<n;i++){
			if(vis[i]) continue;
			for(int j=0;j<n;j++) b[j]=0,viss[j]=0;
			queue <int> q;
			q.push(i);
			viss[i]=1;
			while(!q.empty()){
				int h=q.front();
				q.pop();
				if(vis[h]){
					mx=max(mx,b[h]);
					break;
				}
				for(int v:ve[h]){
					if(!viss[v]){
						b[v]=b[h]+1;
						viss[v]=1;
						q.push(v);
					}
				}
			}
		}
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) solve();	
	return 0;
}
