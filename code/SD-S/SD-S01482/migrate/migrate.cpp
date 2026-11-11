#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,ttt;
int n,d;
int x[2333333];
int dis[2333333];
struct node{
	int xx;
	int step;
};
int bfs(int s,int t){
	int cnt=0;
	memset(dis,0x3f,sizeof dis);
	queue<node> q;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		node op=q.front();
		q.pop();
		int pos=op.xx;
		if(pos==t){
			cnt++;
			continue;
		}
		if(s<t){
			for(int i=pos+1;i<=n and x[i]-x[pos]<=d;i++){
				if(op.step+1<=dis[i]){
					dis[i]=op.step+1;
					q.push({i,op.step+1});
				}
			}
		}
		else{
			for(int i=pos-1;i>=1 and x[pos]-x[i]<=d;i--){
				if(op.step+1<=dis[i]){
					dis[i]=op.step+1;
					q.push({i,op.step+1});
				}
			}
		}
	}
	return cnt;
}
void solve(){
	int ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int ways=bfs(i,j);
			if(ways==2){
				ans++;	
			}
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&ttt);
	while(ttt--){
		solve();
	}
	return 0;
}
