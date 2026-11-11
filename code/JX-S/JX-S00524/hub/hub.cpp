#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int len[20],fa[20],e[20];
vector<int> w[20];
queue<int> q;
int find(int x){
	if(fa[x]==x) return x;
	return find(fa[x]); 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			w[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			w[u].push_back(v);
			w[v].push_back(u);
		}	
		int ans=20;
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k) continue;
			while(!q.empty()) q.pop();
			for(int j=0;j<n;j++){
				len[j+1]=20;
				e[j+1]=0;
				fa[j+1]=0;
				if(i>>j&1){ 
					len[j+1]=0;
					e[j+1]=1;
					fa[j+1]=j+1;
					q.push(j+1);
				}
			}
			int tmp=k;
			for(int j=1;j<=n;j++){
				if(e[j]==0) continue;
				for(auto v:w[j]){
					int x=find(j),y=find(v);
					if(e[v]&&x!=y){
						tmp--;
						fa[x]=y;
					}
				}
			}
			if(tmp>2) continue; 
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:w[u]){
					if(len[v]<=len[u]+1) continue;
					len[v]=len[u]+1;
					q.push(v);
				}
			}
			int num=0;
			for(int i=1;i<=n;i++)
				num=max(num,len[i]);
			ans=min(ans,num);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*


 */
