#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][50005],t[505][50005];
int ans=0;
int fl=true;
struct Node{
	int v,w;
};
bool f[500005];
vector<Node> G[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>k[i];
		if (k[i] > 2){
			fl=false;
		}
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if (fl){
		for (int i=1;i<=n;i++){
			G[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
			G[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
		}
		while (q--){
			int st,en;
			cin>>st>>en;
			queue<int> q;
			memset(f,true,sizeof(f));
			q.push(st);
			int cnt=0;
			f[st]=false;
			while (!q.empty()){
				int x=q.front();
				if (x == en){
					ans=min(ans,cnt);
				}
				for (Node y:G[x]){
					if (f[y.v]){
						f[y.v]=false;
						cnt+=y.w;
						q.push(y.v);
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
