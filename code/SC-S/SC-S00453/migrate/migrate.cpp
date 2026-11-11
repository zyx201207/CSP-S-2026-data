#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+5;
const int inf=LLONG_MAX-2e6-10;
int c,T;
int n,d;
int a[MAXN];
int cnt[MAXN],dis[MAXN];
bool vis[MAXN];
signed main(){
//	freopen("Csub.txt","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		int ans=0ll;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int s=1;s<=n;s++){
			queue<int> q;
			q.push(s);
			for(int i=s;i<=n;i++) dis[i]=inf,cnt[i]=0ll;
			dis[s]=0ll;
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int v=u+1ll;v<=n;v++){
					if(a[v]-a[u]<=d){
						if(dis[v]==dis[u]+1ll) cnt[v]++;
						if(dis[u]+1ll<dis[v]){
							dis[v]=dis[u]+1ll;
							cnt[v]=0ll;
						}
						q.push(v);
					}
					else break;
				}
			}
			for(int i=s;i<=n;i++) if(cnt[i]==2ll) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/