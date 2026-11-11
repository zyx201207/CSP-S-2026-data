#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,c,t,d,idd[N],vis[N],cnt[N],ans;
vector<int> g[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=10){
		while(t--){ans=0LL;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&idd[i]);
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j&&abs(idd[i]-idd[j])<=d) g[i].push_back(j);
			for(int i=1;i<=n;i++){
				queue<int> q;
				while(!q.empty()) q.pop();
				for(int j=1;j<=n;j++) vis[j]=-1,cnt[j]=0;
				vis[i]=0;cnt[i]=1;
				q.push(i);
				while(!q.empty()){
					int now=q.front();
					q.pop();
					
					for(int k=0;k<(int)g[now].size();k++){
						int e=g[now][k];
						if(vis[e]==-1){
							vis[e]=vis[now]+1,cnt[e]=cnt[now],q.push(e);
						}
						else if(vis[now]+1==vis[e]) cnt[e]+=cnt[now];
					}
				}
				for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
			}
			printf("%lld\n",ans);
		}
	}
	if(c==11||c==12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&idd[i]);
			if(d<idd[2]-idd[1]) printf("0\n");
			else cout<<(n-1)*(n-2)/2<<endl;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


*/
