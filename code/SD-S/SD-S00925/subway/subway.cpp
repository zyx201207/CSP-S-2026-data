#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

//struct Edge {
//	LL v;
//};

LL c,n,m,d,q,w[500005];

bool A=true,B=true;

int main() {

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>c>>n>>m>>d>>q;
	if(c>=12&&c<=19) {
		LL T=0;
		vector<LL> g[m+5];
		for(LL i=1; i<=m; i++) {
			cin>>w[i];
		}
		for(LL i=1; i<=n; i++) {
			LL k;
			cin>>k;
			LL a,t;
			cin>>a>>t;
			T=t;
			LL lsto=a,lstt=t;
			for(LL i=2; i<=k; i++) {
				cin>>a>>t;
				g[lsto].push_back(a);
				g[a].push_back(lsto);
				lsto=a,lstt=t;
			}
		}
		/*
		vector<vector<int>>dis(m+5,vector<int>(m+5,T));
		for(LL k=1; k<=m; k++) {
			for(LL i=1; i<=m; i++) {
				for(LL j=1; j<=m; j++) {
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		*/
		for(LL i=1; i<=q; i++) {
			LL sts,ed;
			cin>>sts>>ed;
			vector<LL>dis(m+5, -1);
			queue<LL> q;
			dis[sts]=0;
			q.push(sts);
			while(!q.empty()) {
				LL u=q.front();
				q.pop();
				for(auto v:g[u]){
					if(dis[v]==-1){
						dis[u]=dis[v]+1;
						q.push(v);
					}
				}
			}
			cout<<dis[ed]*T+w[sts]+w[ed]<<endl; //ans
		}
	} else {
		vector<vector<int>>dis(m+5,vector<int>(m+5,0));
		for(LL i=1; i<=m; i++) {
			cin>>w[i];
		}
		for(LL i=1; i<=n; i++) {
			LL k;
			cin>>k;
			LL a,t;
			cin>>a>>t;
			LL lsto=a,lstt=t;
			for(LL i=2; i<=k; i++) {
				cin>>a>>t;
				dis[lsto][a]=t+lstt;
				dis[a][lsto]=lstt+t;
				lsto=a,lstt=t;
			}
		}

		for(LL k=1; k<=m; k++) {
			for(LL i=1; i<=m; i++) {
				for(LL j=1; j<=m; j++) {
					if((dis[i][j]==0)&&(dis[i][k]!=0)&&(dis[k][j]!=0)) {
						dis[i][j]=dis[i][k]+dis[k][j];
					} else if((dis[i][j]!=0)&&(dis[i][k]!=0)&&(dis[k][j]!=0)) {
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					} else {
						continue;
					}
				}
			}
		}
		for(LL i=1; i<=q; i++) {
			LL sts,ed;
			cin>>sts>>ed;
			cout<<dis[sts][ed]+w[sts]+w[ed]<<endl; //ans
		}
	}
	return 0;
}

//qwq 
