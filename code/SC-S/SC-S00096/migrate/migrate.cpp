//小记：
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


const int maxn = 2e6;

int c,t;
int x[maxn],wc[maxn];

//标准链式
struct Edge{
	int u,v,pre,w;//u：起点 v：终点，pre：前边（链式用），w:距离
}edge[maxn*2];
int head[maxn],node;

void add_Edge(int u,int v,int w){
	edge[++node].u = u;
	edge[node].v = v;
	edge[node].w = w;
	edge[node].pre = head[u];
	head[u] = node;
}
int n,d,s_u=0;
void dji(int u,int v,int cnt){
	if(u==v){
		if(wc[u] >=2 && wc[v] >=2){
			cout << u << v;
		}
		cout << cnt;
		return ;
	}
	for(int i=head[u];i;i=edge[i].pre){
		int vs=edge[i].v, w=edge[i].w;
		if(w>d) continue;
		wc[vs]++;
		cnt+=w;
		dji(v,vs,cnt);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			int tem;
			cin >> tem;
			add_Edge(i-1,i,x[1]-x[i-1]);
			add_Edge(i,i-1,x[1]-x[i-1]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				else dji(i,j,0);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}