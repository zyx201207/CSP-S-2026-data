//#include<bits/stdc++.h>
//using namespace std;
//struct Stn{
//	int w;
//	vector<pair<int,int> >v;
//}stn[500010];
//int c,n,m,d,q,ans;
//bool vis[500010];
//int dfs(int x,int y,int cnt){
//	if(x==y) ans=min(ans,cnt);
//	for(auto i:stn[x].v){
//		if(!vis[i.first]){
//			vis[i.first]=1;
//			cnt+=dfs(i.first,y,cnt+i.second+stn[i.first].v[x].second);
//			vis[i.first]=0;
//		}
//	}
//	return cnt;
//}
//int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++) cin>>stn[i].w;
//	for(int i=1;i<=n;i++){
//		int k;
//		cin>>k;
//		vector<pair<int,int> >a;
//		for(int j=1;j<=k;j++) cin>>a[j].first>>a[j].second;
//		for(int j=1;j<=k;j++){
//			for(int l=1;l<=k;l++){
//				if(j!=l) stn[j].v.push_back(a[l]);
//			}
//		}
//	}
//	while(q--){
//		int x,y;
//		ans=INT_MAX;
//		memset(vis,0,sizeof vis);
//		cin>>x>>y;
//		cout<<stn[x].w+stn[y].w+dfs(x,y,0)<<"\n";
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[500010];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		while(k--) cin>>a>>t;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<"\n";
	}
	return 0;
}
