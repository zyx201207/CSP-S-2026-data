#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,int>PII;
const int N=5e5+10;
int n,m,test,d,_;
ll a[N*25],dist[N*25],ans[1010][1010],w[N*10];
int h[N*25],e[N*10],ne[N*10],idx;
bool flag=1;
void add(int x,int y,ll z){
	e[idx]=y;
	ne[idx]=h[x];
	w[idx]=z;
	h[x]=idx++;
	return;
}
int get_id(int x,int num){
	return x+num*n;
}
void dijkstra(int st){
	memset(dist,0x3f,sizeof dist);
	priority_queue<PII,vector<PII>,greater<PII> >q;
	dist[get_id(st,21)]=a[st];
	q.push({a[st],get_id(st,21)});
	for(;!q.empty();){
		PII tt=q.top();q.pop();
		int t=tt.second;
		ll dis=tt.first;
//		printf("!%d %lld\n",t,dis);
		for(int i=h[t];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>dis+w[i]){
				dist[j]=dis+w[i];
				q.push({dist[j],j});
			}
		}
	}
	return;
}
void solve1(){
	for(;_--;){
		int x,y;
		scanf("%d%d",&x,&y);
		dijkstra(x);
		ll ret=dist[get_id(y,21)];
		printf("%lld\n",ret+a[y]);
	}
	return;
}
void solve2(){
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			ans[i][j]=dist[get_id(j,21)]+a[j];
		}
	}
	for(;_--;){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",ans[x][y]);
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%d%d%d%d%d",&test,&m,&n,&d,&_);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll lst=0;
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x;
			ll y;
			scanf("%d%lld",&x,&y);
			if(!lst)lst=y;
			else if(lst!=y)flag=0;
			add(i,get_id(x,21),y);
			add(get_id(x,21),i,y);
		}
	}
	if(n<=1000){
		solve2();
	}else{
		solve1();
	}
	return 0;
}
