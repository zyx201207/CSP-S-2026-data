#include<bits/stdc++.h>
using namespace std;
int n,D;
int a[5000005];
int vis[5000005];
int d[5000005];
struct node{
	int x;
	int cnt;
};
void bfs(int x){
	queue<node>q;
	q.push({x,0});
	d[x]=0;
	while(q.size()){
		node u=q.front();
		q.pop();
		int r=u.x+1;
		while(a[r]-a[u.x]<=D && r<=n){
			if(u.cnt+1==d[r]){
				vis[r]++;
				if(vis[r]<=3){
					q.push({r,u.cnt+1});
				}
			}
			else if(u.cnt+1<d[r]){
				vis[r]=1;
				d[r]=u.cnt+1;
				q.push({r , u.cnt+1});
			}
			r++;
		}
		int l=u.x-1;
		while(a[u.x]-a[l]<=D && l>=1){
			if(u.cnt+1==d[l]){
				vis[l]++;
				if(vis[l]<=3){
					q.push({l,u.cnt+1});
				}
			}
			else if(u.cnt+1<d[l]){
				vis[l]=1;
				d[l]=u.cnt+1;
				q.push({l , u.cnt+1});
			}
			l--;
		}		
	}
	return;
}
void work(){
	int ans=0;
	cin>>n>>D;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(d,0x3f,sizeof(d));
		bfs(i);
		for(int j=1;j<=n;j++){
			if(vis[j]==2){
				ans++;
			}
		}
	}
	cout<<ans/2<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}
