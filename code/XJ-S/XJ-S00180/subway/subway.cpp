#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+10,M=5e5+10;
int C,n,m,kk,T;
ll lw[M];
int k[N];

int read(){
	char ch=getchar();
	int sum=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*f;
}

struct node{
	int v;
	ll w;
	bool operator<(const node &x)const{
		return w>x.w;
	}
};
//vector<node>g[M+N];
int tot,hd[M+N],nxt[M<<1];
node ver[M<<1];
void add(int u,int v,ll w){
	ver[++tot]={v,w};
	nxt[tot]=hd[u];
	hd[u]=tot;
}
ll d[N][M];
ll td[M];
bool vst[M+N];
void dij(int s){
	for(int i=1;i<=m+n;i++)td[i]=1e18;
	td[0]=0;
	priority_queue<node>q;
	memset(vst,0,sizeof(vst));
	q.push({s,0});
	while(q.size()){
		node t=q.top();q.pop();
		if(vst[t.v])continue;
		vst[t.v]=true;
		for(int i=hd[t.v];i;i=nxt[i]){
			int v=ver[i].v;ll w=ver[i].w;
			if(td[v]>w+t.w){
				td[v]=w+t.w;
				q.push({v,td[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	C=read();n=read();m=read();kk=read();T=read();
	for(int i=1;i<=m;i++)lw[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		if(k[i]<=1)continue;
		int id=m+i;
		for(int j=1;j<=k[i];j++){
			int v;ll t;
			v=read();t=read();
			add(id,v,t);
			add(v,id,t);
		}
	}
	if(C<=11||C>19){
		for(int i=1;i<=n;i++){
			if(k[i]<=1)continue;
			dij(i+m);
			for(int j=1;j<=m;j++)
				d[i][j]=td[j];
		}
	}
	while(T--){
		int st,ed;cin>>st>>ed;
		ll ans=1e18;
		if(C<12||C>19){
			for(int i=1;i<=n;i++){
				//if(k[i]<=1)continue;
				if(k[i]<=1||d[i][st]==1e18||d[i][ed]==1e18)continue;
				ans=min(ans,d[i][st]+d[i][ed]);
			}
			cout<<ans+lw[st]+lw[ed]<<'\n';
		}else{
			dij(st);cout<<td[ed]+lw[st]+lw[ed]<<'\n';
		}
		
	}
	return 0;
}
