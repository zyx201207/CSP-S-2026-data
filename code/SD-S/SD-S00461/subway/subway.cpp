#include<bits/stdc++.h>
//#define int long long
using namespace std;
long long a,b,oo,c,ooo,d[500010],f[500010],p[500010];
int w1[110][500010],w2[510][500010];
struct nn {
	long long a,b;
};
vector<nn>v[500010],h[500010];
int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void bfs(int x) {
	queue<int>q;
	q.push(x);
	for(int i=1;i<=b;i++) f[i]=2e17;
	f[x]=0;
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		for(auto it:v[x]) {
			int i=it.a,w=it.b;
			for(int j=1; j<=p[i]; j++) {
				cout<<w1[p[i]][j]<<" "<<f[x]+w+w2[p[i]][j]<<"\n";
				if(f[w1[p[i]][j]]>f[x]+w+w2[p[i]][j]){
					f[w1[p[i]][j]]=f[x]+w+w2[p[i]][j];
					q.push(w1[p[i]][j]);
				}
			}
		}
	}
}
signed main() {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>oo>>a>>b>>c>>ooo;
	for(int i=1; i<=b; i++) {
		cin>>d[i];
	}
	for(int i=1; i<=a; i++) {
		int x;
		cin>>x;
		p[i]=x;
		for(int j=1; j<=x; j++) {
			cin>>w1[i][j]>>w2[i][j];
			v[w1[i][j]].push_back({i,w2[i][j]});
		}
	}

	while(ooo--) {
		int x,y;
		cin>>x>>y;
		bfs(x);
		cout<<f[y]<<"\n";
	}
	return 0;
}
//对于所有 v (1 ≤ v ≤ m)，经过第 v 个地铁站的线路数均不超过 d；
