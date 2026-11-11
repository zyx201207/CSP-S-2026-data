#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int c,t,n,d,a[N],ans;
void get(int x){
	queue<int> q;
	int cnt[N],dis[N];
	bool vis[N]={0};
	cnt[x]=1;dis[x]=0;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=1;
		for(int i=u+1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i]-a[u]<=d){
				if(dis[i]==0) dis[i]=dis[u]+1;
				if(dis[i]==dis[u]+1) cnt[i]+=cnt[u];
				q.push(i);
			}
		}
	}
	for(int i=x+1;i<=n;i++){
		if(cnt[i]==2){
			ans++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			get(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/