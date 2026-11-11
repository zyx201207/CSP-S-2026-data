#include<iostream>
#include<queue>
#include<cstring>
#define ll long long
using namespace std;
ll c,T,n,d,a[2000005],minn,ans,ans2,b[200005],vis[200005];
void dfs(ll y,ll now,ll cnt){
	if(now>y) return;
	if(now==y&&cnt==minn){
			ans++;
	}
	for(int i=now+1;i<=y&&a[i]-a[now]<=d;i++)
		dfs(y,i,cnt+1);
}
void bfs(ll x,ll y){
	memset(vis,0,sizeof vis);
	queue<int> q;
	q.push(x);
	b[x]=0,vis[x]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now==y)
			return;
		for(int i=now+1;i<=y&&abs(a[i]-a[now])<=d;i++){
			if(!vis[i])
				q.push(i),b[i]=b[now]+1,vis[i]=1;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&T);
	while(T--){
		ans2=0;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=4;i<=n;i++){
			for(int j=1;j<i-2;j++){
				bfs(j,i);
				minn=b[i],ans=0;
				dfs(i,j,0);
//				cout<<endl<<i<<" "<<j<<" "<<minn<<" "<<ans<<endl;
				if(ans==2)
				    ans2++;
			}
		}
		printf("%d\n",ans2);
	}
	return 0;
}
