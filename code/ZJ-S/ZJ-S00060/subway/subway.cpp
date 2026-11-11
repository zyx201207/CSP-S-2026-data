#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,ce[500005];
ll w[500005],dis[100005],val[2000005];
vector<ll> a[505],t[505];
int h[1000005],nxt[2000005],to[2000005],cnt;
bool inq[100005];
void add(int u,int v,ll va){
	cnt++;
	nxt[cnt] = h[u],to[cnt] = v,val[cnt] = va;
	h[u] = cnt;
}
void spfa(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(st);
	inq[st] = 1;
	dis[st] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for(int i = h[u];i;i = nxt[i]){
			int v = to[i];
			if(dis[v] > dis[u] + val[i]){
				dis[v] = dis[u] + val[i];
				if(!inq[v]){
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++) scanf("%lld",&w[i]);
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%d",&k);
		for(int j = 0;j < k;j++){
			ll v,ti;
			scanf("%lld %lld",&v,&ti);
			a[i].push_back(v);
			t[i].push_back(ti);
			ce[a[i][j]]++;
		}
		for(int j = 0;j < k;j++){
			for(int l = j+1;l < k;l++){
				int u = a[i][j],v = a[i][l];
				ll ti = t[i][j]+t[i][l];
				add(ce[u]*m+u,ce[v]*m+v,ti);
				add(ce[v]*m+v,ce[u]*m+u,ti);
			}
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= ce[i];j++){
			for(int l = 1;l <= ce[i];l++)
				add(j*m+i,l*m+i,(ll)0);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		spfa(m+x);
		printf("%lld\n",dis[m+y]+w[x]+w[y]);
	}
	return 0;
}