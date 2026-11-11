#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int c,t,n,k,x,y,b[maxn],dis[35],cnt,ans;
bool vis[maxn];
vector <int> e[maxn];
void dfs(int now){
	vis[now]=1;
	for(int i:e[now]) if(!vis[i] && b[i]) dfs(i);
}void dfs(int now,int pre){for(int i:e[now]) if(i!=pre) dis[i]=dis[now]+1,dfs(i,now);}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t ;
	while(t--){
		ans=1e9;
		cin >> n >> k ;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++) cin >> x >> y ,e[x].push_back(y),e[y].push_back(x);
		for(int s=1;s<(1 << n);s++){
			if(__builtin_popcount(s)==k){
				cnt=0;
				for(int i=1;i<=n;i++) b[i]=((s >> (i-1)) & 1),vis[i]=0;
				for(int i=1;i<=n;i++) if(!vis[i] && b[i]) cnt++,dfs(i);
//				cout << " " << s << " " << cnt << "\n" ;
				if(cnt>2) continue;
				int tmp=0;
				for(int i=1;i<=n;i++){
					if(!b[i]){
						dis[i]=0,dfs(i,0);
						int mx=1e9;
						for(int j=1;j<=n;j++) if(b[j]) mx=min(mx,dis[j]);
						tmp=max(tmp,mx);
					}
				}ans=min(ans,tmp);
			}
		}cout << ans << "\n" ;
	}return 0;
}
/*
No cost too great.
No mind to think.
No will to break.
No voice to cry suffering.
......
You are the hollow knight.
*/