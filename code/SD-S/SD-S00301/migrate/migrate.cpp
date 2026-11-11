#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 600005
int n,m;
int a[N];
int head[N];
struct Edge{
	int f;
	int t;
	int v;
	int nxt;
}edge[10000005];
int ttt=0;
void add_edge(int f,int t,int v){
	ttt++;
	edge[ttt].f=f;
	edge[ttt].t=t;
	edge[ttt].v=v;
	edge[ttt].nxt=head[f];
	head[f]=ttt;
	return ;
}
struct Dot{
	int id;
	int fr;
	bool operator >(const Dot & a)const{
		return fr<a.fr;
	}
	bool operator <(const Dot & a)const{
		return fr>a.fr;
	}
};
priority_queue<Dot>q;
bool vis[N];
int dis[N];
int cnt[N];
void dij(int st){
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
		vis[i]=0;
		cnt[i]=0;
	}
	Dot k;
	k.id=st;
	k.fr=0;
	dis[st]=0;
	cnt[st]=1;
	q.push(k);
	while(!q.empty()){
		Dot kl=q.top();
		q.pop();
		int u=kl.id;
		int f=kl.fr;
		if(f!=dis[u]||vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			int t=edge[i].t;
			int v=edge[i].v;
			if(dis[t]<=f+v){
				if(dis[t]==f+v){
					cnt[t]+=cnt[u];
				}
				continue;
			}
			dis[t]=f+v;
			Dot kk;
			kk.id=t;
			kk.fr=dis[t];
			q.push(kk);
			cnt[t]=cnt[u];
		}
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ccc,T;
	cin>>ccc>>T;
	while(T--){
		memset(head,0,sizeof(head));
		memset(a,0,sizeof(a));
		ttt=0;
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m){
					add_edge(i,j,1);
				}
			}
		}
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
