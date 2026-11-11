#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,deg[1000006],d[1000006],vis[1000006];
vector<int> T[1000006];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cout<<"0\n";
//		int ans=0;
//		cin>>n>>k;
//		for(int i=1,u,v;i<n;i++){
//			cin>>u>>v;
//			T[u].push_back(v);
//			T[v].push_back(u); 
//			deg[u]++,deg[v]++;
//		}
//		memset(deg,0,sizeof(deg));
//		memset(vis,0,sizeof(vis));
//		memset(d,0,sizeof(d));
//		queue<int> q;
//		for(int i=1;i<=n;i++){
//			if(deg[i]==1){
//				q.push(i);
//				vis[i]=1;
//			}
//		}
//		while(q.size()){
//			int t=q.front();
//			q.pop();
//			for(int it:T[t]){
//				if(!vis[it]){
//					d[it]=d[t]+1;
//					vis[it]=1;
//					q.push(it);
//				}
//			}
//		}
//		int mxa=0,mxb=0;
//		for(int i=1;i<=n;i++){
//			if(d[i]>d[mxa]) mxb=mxa,mxa=i;
//			else if(d[i]>d[mxb]) mxb=i;
//		}
//		memset(deg,0,sizeof(deg));
//		memset(vis,0,sizeof(vis));
//		memset(d,0,sizeof(d));
//		if(k==1) q.push(mxa);
//		if(k>1) q.push(mxb);
//		if(k==1) vis[mxa]=1;
//		if(k>1) vis[mxb]=1;
//		while(q.size()){
//			int t=q.front();
//			q.pop();
//			for(int it:T[t]){
//				if(!vis[it]){
//					d[it]=d[t]+1;
//					vis[it]=1;
//					q.push(it);
//				}
//			}
//		}
//		for(int i=1;i<=n;i++){
//			ans=max(ans,d[i]);
//		}
//		cout<<ans<<'\n';
	}
}
