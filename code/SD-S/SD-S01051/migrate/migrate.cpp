#include<iostream>
#include<cstdio>
#include<queue>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int op,T,n,d,a[2001000],vis[2001000],ans;
struct node{
	int x,w;
};
priority_queue<node> q;
bool operator < (node x,node y){
	return x.w>y.w;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&op,&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int maxn=inf,cnt=0;
				q.push(node{i,0});
				while(!q.empty()){
					node t=q.top();
					q.pop();
					if(t.w>maxn||cnt>2) continue;
					if(t.x==j){
						maxn=min(maxn,t.w);
						cnt++;
					}
					for(int k=t.x+1;k<=j;k++){
						if(a[k]-a[t.x]<=d){
							q.push(node{k,t.w+1});
						}
					}
				}
				if(cnt==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

