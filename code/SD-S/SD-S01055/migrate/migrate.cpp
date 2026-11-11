#include<bits/stdc++.h>
#define int long long
#define PLL pair<int,int>
#define endl '\n'
using namespace std;
const int N=5e3+5,M=2e6+5;
int kkll,okkll,n,k,a[M],dis[N],cnt[N],vis[N],ans;
vector<int> tu[N];
void dij(int x){
	priority_queue<PLL,vector<PLL>,greater<PLL> > q;
	q.push({0,x});
	dis[x]=0,cnt[x]=1;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int y:tu[x]){
			if(dis[x]+1<dis[y]){
				dis[y]=dis[x]+1;
				cnt[y]=cnt[x];
				q.push({dis[y],y});
			}
			else if(dis[x]+1==dis[y]){
				//cout<<x<<" "<<y<<endl;
				cnt[y]+=cnt[x];
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&okkll,&kkll);
	while(kkll--){
		ans=0;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),tu[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=k) tu[i].push_back(j);
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[j]=1e18,cnt[j]=vis[j]=0;
			dij(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					//cout<<i<<' '<<j<<' '<<dis[j]<<endl;
					ans++;	
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
