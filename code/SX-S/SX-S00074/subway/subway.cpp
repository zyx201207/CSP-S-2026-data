#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
priority_queue<PII,vector<PII>,greater<PII>> q;
int dis[500005],w[500005],k[500005];
vector<int> dt[500005],z[500005];
vector<PII> h[500005];
void dj(int s){
	q.push({0,s});
	memset(dis,63,sizeof(dis));
	dis[s]=0;
	while(!q.empty()){
		int x=q.top().fi;
		int y=q.top().se;
		q.pop();
		if(dis[y]!=x) continue;
		for(auto ed:h[y]){
			int u=ed.fi;
			int v=ed.se;
			if(dis[u]>dis[y]+v){
				dis[u]=dis[y]+v;
				q.push({dis[u],u});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin >>w[i];
	}
	for(int j=1;j<=n;++j){
		cin >>k[j];
		for(int i=1;i<=k[j];++i){
			int a,t;cin >>a>>t;
			dt[i].push_back(a);
			z[i].push_back(t);
		}
	}

	for(int i=1;i<=n;++i){
		for(auto j:dt[i]){
			for(auto x:dt[i]){
				if(j==x){
					continue;
				}
				h[j].push_back({x,z[i][x-1]+w[x]});
				h[x].push_back({j,z[i][j-1]+w[j]});
				for(auto y:h[dt[i][j-1]]){
					cout<<y.se<<" ";
				}
				cout<<endl;
			}
		}
	}
	for(int i=1;i<=q;++i){
		int qi,zh;cin >>qi>>zh;
		//dj(qi);
		cout<<dis[zh]<<endl;
	}
	return 0;
}
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7