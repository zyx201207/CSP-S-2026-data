#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[505];
long long c1,c2,c3,c4;
long long k;
struct o{
	long long to,val;
	bool operator <(const o& other)const{
		return val>other.val;
	}
};
long long dis[505][505];
vector <o> g[600005];
long long vis[600005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> m >> n >> d >>q;
	if (c>=7 && c<=11){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j){
					dis[i][j]=0;
					dis[j][i]=0;
				}
				else{
					dis[i][j]=1e18;
					dis[j][i]=1e18;
				}
				
			}
		}
		for (int i=1;i<=n;i++){
			cin >> w[i];
		}
		for (int i=1;i<=m;i++){
			cin >> k;
			if (k==1){
				cin >> c1 >> c2;
			}
			else{
				cin >> c1 >> c2 >> c3 >> c4;
				dis[c1][c3]=min(dis[c1][c3],c2+c4);
				dis[c3][c1]=min(dis[c1][c3],c2+c4);
			}
		}
		for (int i=1;i<=n;i++){
			for (int ii=1;ii<=n;ii++){
				for (int iii=1;iii<=n;iii++){
					dis[ii][iii]=min(dis[ii][iii],dis[ii][i]+dis[i][iii]);
					dis[iii][ii]=min(dis[ii][iii],dis[ii][i]+dis[i][iii]);
				}
			}
		}
		while (q--){
			cin >> c1 >> c2;
			cout << w[c1]+w[c2]+dis[c1][c2] << '\n';
		}
		return 0;
	}
	long long tot=n;
	for (int i=1;i<=n;i++){
		cin >> w[i];
	}
	for (int i=1;i<=m;i++){
		cin >> k;
		tot++;
		for (int j=1;j<=k;j++){
			cin >> c1 >> c2;
			g[c1].push_back({tot,c2});
			g[tot].push_back({c1,c2});
		}
	}
	while (q--){
		cin >> c1 >> c2;
		long long ans=0;
		ans+=w[c1]+w[c2];
		priority_queue<o> q;
		for (int i=1;i<=tot;i++){
			vis[i]=1e18;
		}
		q.push({c1,0});
		while (!q.empty()){
			auto xz=q.top();
			q.pop();
			if (vis[xz.to]<=xz.val){
				continue;
			}
			vis[xz.to]=xz.val;
			if (xz.to==c2){
				cout << xz.val+ans << '\n';
				break;
			}
			for (auto i:g[xz.to]){
				if (i.val+xz.val<vis[i.to]){
					q.push({i.to,xz.val+i.val});
				}
			}
		}
	}
	return 0;
}