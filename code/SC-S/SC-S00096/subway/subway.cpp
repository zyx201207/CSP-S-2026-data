//小记：
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int c,n,m,d,q;
//这个c不用，理论上可以直接抛

const int maxn = 500+100;

//标准链式
struct Edge{
	int u,v,pre,l;//u：起点 v：终点，pre：前边（链式用），l：本边所属线路
}edge[maxn*2];
int head[maxn],node;

void add_Edge(int u,int v,int l){
	edge[++node].u = u;
	edge[node].v = v;
	edge[node].l = l;
	edge[node].pre = head[u];
	head[u] = node;
}
const int maxm = 5e5+10;
struct Stat{
	int w;//进入站台时间
	int t[25];//最多经过20条地铁线路，t有值则代表本站经过该线路，值代表从此站换乘i的时间。
	int ml; // max line,数字最高的线路。
}s[maxm];

int nowline = 0, start_u =0;
int vis[maxn];
void dji(int u,int v,int cnt){
	if(u == v){
		cout << cnt+s[u].w;
		return;
	}
	vis[u] = 1;
	for(int i=head[u];i;i=edge[i].pre){
		int vs=edge[i].v, ls=edge[i].l;
		if(vis[vs] == 1) continue;
		for(int j=1;j<=25;j++){
			if(s[u].t[j] && j==ls){
				//本边可去此线路，
				//如果u是第一点，那么nowline就是它本身
				if(u == start_u){
					nowline = ls;
					//加上进站时间
					cnt += s[u].w;
				} 
				else if(nowline!=ls){
					cnt += s[u].t[nowline] + s[u].t[ls];
					nowline = ls;
				}
				dji(vs,v,cnt);
				continue;
			}
		}
	}
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> s[i].w;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		int las=0;
		for(int j=1;j<=2*k;j++){
			int a,t;
			cin >> a >> t;
			if(las==0){
				//孩子你就是第一个站。
				s[a].t[i] = t;
				s[a].ml = max(i,s[a].ml);
				las = a;
				continue;
			}
			s[a].t[i] = t;
			s[a].ml = max(i,s[a].ml);
			add_Edge(las,a,i);
			add_Edge(a,las,i);
			continue;
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin >> u >> v;
		start_u = u;
		dji(u,v,0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}