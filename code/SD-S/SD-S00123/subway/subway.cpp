#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,l,r;
vector<long long> a[505];
vector<long long> t[505];//t[x][y] 从地体线y的站台走到 站厅 x
struct node {
	long long v,w;
};
vector<long long> pp[505];
vector<node> e[505];
long long dis[505],f[505];
long long ppp[505];
long long w[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(long long i=1; i<=n; i++) {
		cin>>ppp[i];
		a[i].push_back(ppp[i]);
		t[i].push_back(ppp[i]);
		for(long long j=1; j<=m; j++) {
			t[i].push_back(-1);
		}
		for(long long j=1; j<=ppp[i]; j++) {
			long long x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i][x]=y;
			pp[x].push_back(i);
		}
	}
//	for(long long i=1;i<=n;i++)
//	{
//		for(long long j=1;j<=ppp[i];j++)
//		{
//			cout<<t[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(long long i=1; i<=m; i++) {//地铁站
		if(pp[i].size()>=2) {
			for(long long j=0; j<(long long)pp[i].size(); j++) {
				for(long long w=0; w<(long long)pp[i].size(); w++) {
					if(pp[i][j]!=pp[i][w]) {
						if(t[pp[i][w]][i]>=1&&t[pp[i][j]][i]>=1) {
							e[pp[i][j]].push_back({pp[i][w],t[pp[i][w]][i]+t[pp[i][j]][i]});
						}

					}
				}
			}
		}

	}
	while(q--) {
		cin>>l>>r;
		long long ans=1e9;
		for(long long i:pp[l]) {
			for(long long j:pp[r]) {
				memset(dis,0x3f,sizeof(dis));
				memset(f,0,sizeof(f));
				priority_queue<pair<long long,long long>> q;
				q.push({0,i});
				dis[i]=0;
				while(!q.empty()) {
					auto t=q.top();
					q.pop();
					if(f[t.second]==1) {
						continue;
					}
					f[t.second]=1;
					for(auto p:e[t.second]) {
						dis[p.v]=min(dis[p.v],dis[t.second]+p.w);
						q.push({-dis[p.v],p.v});
					}
				}
				ans=min(ans,dis[j]+t[i][l]+t[j][r]);
//				for(long long gj=1;gj<=n;gj++)
//				{
//					cout<<dis[gj]<<" ";
//				}
			}
		}
		cout<<ans+w[l]+w[r]<<"\n";
	}
	return 0;
}


