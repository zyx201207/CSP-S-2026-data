#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qq,idx;
int h[537537],ne[2333333],to[2333333],e[2333333];
int chu[537537];
int dis[537537];
void insert(int a,int b,int c){
	to[idx]=b;
	e[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}
struct node{
	int x;
	int step;
};
void solve(){
	memset(dis,0x3f,sizeof dis);
	int s,t;
	scanf("%lld%lld",&s,&t);
	dis[s]=0;
	queue<node> q;
	q.push({s,0});
	while(!q.empty()){
		node op=q.front();
		q.pop();
		int pos=op.x;
		int cost=op.step;
		for(int i=h[pos];i!=-1;i=ne[i]){
			int too=to[i];
			int ee=e[i];
			if(cost+ee<dis[too]){
				dis[too]=cost+ee;
				q.push({too,cost+ee});
			}
		}
	}
	printf("%lld\n",dis[t]+chu[s]+chu[t]);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++){
		scanf("%lld",&chu[i]);
	}
	for(int i=1;i<=n;i++){
		int res=500000+i;
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%lld%lld",&a,&t);
			insert(res,a,t);
			insert(a,res,t);
		}
	}
	while(qq--){
		solve();
	}
	return 0;
}
