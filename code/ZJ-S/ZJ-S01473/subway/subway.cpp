#include<bits/stdc++.h>
//#define int long long
using namespace std;
priority_queue<pair<int,int>>q;
int vis[10100],a[100010],t[100010],n,m,c,d,Q,ans[5010][5010],w[1000100],l1[100010],r1[100010];
vector<pair<int,int>>edges[10010];
void dij(int s){
	memset(vis,0,sizeof vis);
	while(!q.empty())q.pop();
	q.push({0,s});
	ans[s][s]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto it:edges[x]){
			int y=it.first,z=it.second;
			if(ans[s][y]>ans[s][x]+z){
				ans[s][y]=ans[s][x]+z;
				q.push({-ans[s][y],y});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int l=1;l<j;l++){
				edges[a[l]].push_back({a[j],t[l]+t[j]});
				edges[a[j]].push_back({a[l],t[l]+t[j]});
			}
		}
	}
	//if(c<=11){
		for(int i=1;i<=m;i++){
			dij(i);
		}
		for(int i=1;i<=Q;i++){
			cin>>l1[i]>>r1[i];
			cout<<ans[l1[i]][r1[i]]+w[r1[i]]+w[l1[i]]<<"\n";
		}	
//	}
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++){
//			cin>>a[i][j]>>t[i][j];
//		}
//	}
//	
	return 0;
}
