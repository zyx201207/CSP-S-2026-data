#include<bits/stdc++.h>
using namespace std;
int C,T;
int N;
typedef long long ll;
typedef pair<ll,int> P;
ll D;
ll cnt;
ll a[2000010];
int edge[2000010];
ll dis[2000010];
bool vis[2000010];
bool flag[2000010];
void dij(int x){
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,x));
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
	memset(vis,false,sizeof(vis)); 
	memset(flag,false,sizeof(flag));
	while(que.size()){
		int t=que.top().second;
		que.pop();
		if(vis[t]){
			continue;
		}
		vis[t]=1;
		for(int i=1;i<=edge[t];i++){
			int v=i+t;
			if(dis[v]==dis[t]+1){
				if(flag[v]==false){
					flag[v]=true;
				    cnt++;
				}
				else{
					cnt--;
					flag[v]=false;
				}
			}
			if(dis[v]>dis[t]+1){
				dis[v]=dis[t]+1;
				if(flag[v]==true){
					cnt--;
				}
				flag[v]=false;
				que.push(P(dis[v],v));
			}
		}
	}
}
void solve(){
	for(int i=1;i<=N;i++){
		int l=1,r=N-i;
		while(l<r){
			int mid=(l+r+1)/2;
			if(a[i+mid]-a[i]<=D){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		edge[i]=l;
	}
	for(int i=1;i<=N;i++){
		dij(i);
	}
	printf("%d\n",cnt);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&N,&D);
		for(int i=1;i<=N;i++){
			scanf("%lld",&a[i]);
		}
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

