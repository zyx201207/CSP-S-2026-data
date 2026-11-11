#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t,n,nxt[N];
ll a[N],d,dis[N],cnt[N];
vector<int>nol,nor,hvl,hvr;
queue<int>q;
bool vis[N];
void bfs(int s){
	q.emplace(s);
	for(int i=1;i<=n;++i)dis[i]=1e18,cnt[i]=0;
	dis[s]=0;cnt[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=u+1;i<nxt[u];i++){
			if(dis[i]==dis[u]+1)cnt[i]+=cnt[u];
			else if(dis[i]<dis[u]+1)continue;
			else cnt[i]=cnt[u],dis[i]=dis[u]+1,q.emplace(i);
		}
	}
}
void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	a[n+1]=0;
	if(c<=10){//40pts
		for(int i=1;i<=n;i++)
			nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a;
		ll ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i;j<=n;j++)ans+=(cnt[j]==2);
		}
		printf("%lld\n",ans);
		return;
	}else if(13<=c&&c<=14){//8pts
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=d)continue;
			int bf=upper_bound(a+1,a+n+1,a[i]-d)-a-1;
			int bf2=upper_bound(a+1,a+n+1,a[i-2]-d)-a-1;
			if(i-bf==2)ans+=(bf-bf2);
		}
		printf("%lld\n",ans);
		return;
	}
	return;
	for(int i=1;i<=n;i++){
		nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a;
		if(nxt[i]>n)continue;
		if(nxt[i]-i-1>2&&a[nxt[i]-1]-a[i]<=d&&a[nxt[i]]-a[i+1]<=d){
			nol.emplace_back(i),nor.emplace_back(nxt[i]);
			printf("%lld %lld\n",a[nxt[i]-1]-a[i],a[nxt[i]]-a[i+1]);
			printf("no %d %d\n",i,nxt[i]);
		}else if(nxt[i]==i+3&&a[i+3]-a[i+1]<=d){
			hvl.emplace_back(i),hvr.emplace_back(nxt[i]);
			printf("hv %d %d\n",i,i+3);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}