#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		vector<vector<int>>adj(n+2);
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d)adj[j].push_back(i);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			queue<int>q;
			vector<int>dfn(n+2);
			vector<int>low(n+2);
			q.push(i);
			low[i]=1;
			dfn[i]=1;
			while(!q.empty()){
				for(int v:adj[q.front()]){
					if(low[v]>low[q.front()]+1||low[v]==0){
						low[v]=low[q.front()]+1;
						dfn[v]=1;
						q.push(v);
					}else if(low[v]==low[q.front()]+1){
						dfn[v]++;
					}
				}
				q.pop();
			}
			for(int i=1;i<=n;i++){
				if(dfn[i]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
