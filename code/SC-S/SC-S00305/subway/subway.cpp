#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q,w[500010],k[510],t[510][50010];
int g[510][510],f[510][510];
unordered_map<int,vector<int>>mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x7f,sizeof(g));
	memset(f,0x3f,sizeof(f));
	//1.读入
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int xx;
			cin>>xx>>t[i][xx];
			mp[xx].push_back(i);
		}
	}
	
	//2.建图
	for(auto o:mp){
		vector<int>v=o.second;
		for(int i=0;i<v.size();i++){
			for(int j=i+1;j<v.size();j++){
				f[v[j]][v[i]]=f[v[i]][v[j]]=g[v[j]][v[i]]=g[v[i]][v[j]]=min(g[v[i]][v[j]],t[v[i]][o.first]+t[v[j]][o.first]);
			}
		}
	}
	
	//3.跑floyd
	for(int r=1;r<=n;r++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[r][i]+f[r][j]);
			}
		}
	}
	//4.询问
	while(q--){
		int x,y,ans=0x7f7f7f7f;
		cin>>x>>y;
		vector<int>vx=mp[x],vy=mp[y];
		for(int i=0;i<vx.size();i++){
			for(int j=0;j<vy.size();j++){
				ans=min(ans,t[vx[i]][x]+f[vx[i]][vy[j]]+t[vy[j]][y]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/