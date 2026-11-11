#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
int c,n,m,d,q;
cin>>c>>n>>m>>d>>q;
int w[m+1];
//n线路，m站 
vector<pair<int,int>> a[n+m+1];
//a[i].f是目的地，a[i].s是耗时 
int num;
for(int i=1;i<=m;i++){
	cin>>w[i];
}
for(int i=1;i<=n;i++){
	int nu,now;
	cin>>num;
	now = i+m;
	for(int j=1;j<=num;j++){
		int to,time;
		cin>>to>>time;
		a[now].push_back({to,time});
		a[to].push_back({now,time});
	}
}
int ans[n+m+1];
bool vis[n+m+1];
while(q--){
	int s,e;
	cin>>s>>e;
	for(int i=1;i<=n+m;i++){vis[i] = 0;ans[i] = LLONG_MAX;}
	ans[s] = 0;
	int vn = s;
	vis[vn] = 1;
	while(true){
		for(int i=0;i<a[vn].size();i++){
			long long vv = a[vn][i].first,vt =a[vn][i].second;
			if(vis[vv]==0){
				ans[vv] = min(ans[vv],ans[vn]+vt);
			}
		}
		vis[vn] = 1;
		int mm = LLONG_MAX;
		for(int i=1;i<=m+n;i++){
			if(vis[i] == 0&&ans[i]<mm){
				vn = i;
				mm=ans[i];
			}
		}
		if(vn == e||vis[e] == 1){
			break;
		}
	}
//	cout<<q<<" ";
//	for(int i=1;i<=n+m;i++){
//		cout<<ans[i]<<" ";
//	}
//	cout<<endl;
	cout<<ans[e]+w[s]+w[e]<<endl;
}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
