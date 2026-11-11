#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,ans,mi;
ll d,x[2000005];
map< int,int >mp;
struct node{
	int xus,st;
};
bool bfs(int s,int f){
	mp.clear();
	mi=1e9;
	queue< node >q;
	q.push(node{s,0});
	while(!q.empty()){
		int hx=q.front().xus,ht=q.front().st;
		q.pop();
		if(hx==f){
			mp[ht]++;
			mi=min(mi,ht);
			continue;
		}
		if(ht>mi) continue;
		for(int i=hx+1;i<=n;i++){
			if(x[i]-x[hx]>d) break;
			q.push(node{i,ht+1});
		}
	}
	if(mp[mi]==2) return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
				if(bfs(i,j)) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}