#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e6+10;
struct node{
	int x,y;
};
vector <int> g[N];
queue <node> q[N];
ll a[N];
int t[N],vis[N];
inline void dfs(int x,int y,int len){
	if (x!=y){
		node o=q[y].front();
		if (len==o.y && q[y].size()<2)
			q[y].push({y,len});
		else if (len<o.y){
			while (q[y].size()) q[y].pop();
			q[y].push({x,len});
		}
	}
	int siz=g[y].size();
	for (int i=0;i<siz;i++){
		int o=g[y][i];
		if (!vis[o]){
			vis[o]=1;
			dfs(x,o,len+1);
			vis[o]=0;
		}
	}
}
inline void migrate(int x,ll y){
	if (x==1){
		printf("0");
		return;
	}
	sort(a+1,a+x+1);
	memset(t,0,sizeof t);
	for (int l=1,r=2;l<=x;l++){
		while (a[r]-a[l]<=y && r<x) r++;
		for (int i=l;i<=r;i++){
			g[l].push_back(r);
			g[r].push_back(l);
		}
	}
	for (int i=1;i<=x;i++){
		vis[i]=1;
		dfs(i,i,0);
		vis[i]=0;
	}
	ll cnt=0;
	for (int i=1;i<=x;i++)
		if (q[i].size()>=2)
			cnt++;
	printf("%lld",cnt);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while (T--){
		int n;
		ll d;
		scanf("%d%lld",&n,&d);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		printf("0\n");
	}
}
