#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
const int N = 5e5+10;
struct Node{
	int to,next,len;
}a[N];
int c,n,m,f,q,s,w,b[N],pre[N],d[N],k,l,e[N],g[N];
void add(int u,int v,int l){
	a[++k] = {v,pre[u],l};
	pre[u] = k;
}
priority_queue<pi> qw;
//AK666
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> f >> q;
	for(int i = 1;i<=m;i++){
		cin >> b[i];
	}
	for(int i = 1;i<=n;i++){
		cin >> l;
		for(int o = 1;o<=l;o++){
			cin >> e[o] >> g[o];
		}
		for(int j = 1;j<=l;j++){
			for(int aw = 1;aw<=l;aw++){
				if(j!=aw){
					int len = g[j]+g[aw];
					add(e[j],e[aw],len);
				}
			}
		}
	}
	while(q--){
		cin >> s >> w;
		qw.push({s,1});
		memset(d,0x3f,sizeof(d));
		while(!qw.empty()){
			int h1 = qw.top().first,h2 = qw.top().second;
			qw.pop();
			for(int i = pre[h2];i;i = a[i].next){
				int to = a[i].to;
				if(a[i].len+h1<d[to]){
					d[to] = a[i].len+h1;
					qw.push({d[to],to});
				}
			}
		}
		cout << d[w]+b[s]+b[w]-1 << '\n';
	}
	return 0;
}
