#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
vector<int> edge[1000005];
bool vis[1000005],vis2[1000005];
int calc(vector<int> vec){
	int ret=0;
	queue<pair<int,int> > q;
	for (int i=1;i<=n;i++)
	  vis2[i]=0;
	int len=vec.size();
	for (int i=0;i<len;i++)
	  q.push(make_pair(vec[i],0));
	while(!q.empty()){
		int now=q.front().first,dis=q.front().second;
		q.pop();
		ret=max(ret,dis);
		len=edge[now].size();
		for (int i=0;i<len;i++){
			if (vis[edge[now][i]]||vis2[edge[now][i]])
			  continue;
			vis2[edge[now][i]]=1;
			q.push(make_pair(edge[now][i],dis+1));
		}
	}
	return ret;
}
void dfs(vector<int> vec){
	int len=vec.size();
	if (len==k){
		ans=min(ans,calc(vec));
		return ;
	}
	for (int i=0;i<len;i++){
		int nxt=edge[vec[i]].size();
		for (int j=0;j<nxt;j++){
			if (vis[edge[vec[i]][j]])
			  continue;
			vector<int> vec2=vec;
			vec2.push_back(edge[vec[i]][j]);
			vis[edge[vec[i]][j]]=1;
			dfs(vec2);
			vis[edge[vec[i]][j]]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdin);
	cin>>c>>t;
	while(t--){
		ans=1000000000;
		cin>>n>>k;
		for (int i=1;i<=n;i++)
		  edge[i].clear();
		for (int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				vector<int> nul;
				nul.push_back(i);
				nul.push_back(j);
				vis[i]=1;
				vis[j]=1;
				dfs(nul);
				vis[i]=0;
				vis[j]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
