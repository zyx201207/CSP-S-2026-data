#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> w(15);
vector<int> k(5)
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	vector<int> zd[15];
	vector<int> a[5];
	vector<vector<int> > t(5,vector<int> (15,0));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aa,tt;
			cin>>aa>>tt;
			zd[aa].push_back(j);
			a[i].push_back(aa);
			t[i][aa]=tt;
		}
	}
	while(q--){
		vector<bool> vis(15,true);
		vector<int> dis(15,true);
		int ans=0;
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		vis[x]=false;
		dis[x]=0;
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=0;i<zd[x].size();i++){
			for(int j=0;j<a[zd[x][i]].size();j++){
				if(vis[a[zd[x][i]][j]]) q.push(a[zd[x][i]][j]); 
			}
		}
	}
	return 0;
}
