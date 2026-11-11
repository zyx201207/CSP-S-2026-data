#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
int n,x[2000005];
int nxt[2000005];
int cnt[2000005];
int dis[200005];
void bfs(int s){
	queue<int>q;
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
		cnt[i]=0;
	} 
	q.push(s);
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=x+1;i<=nxt[x];i++){
			if(dis[i]>=dis[x]+1){
				if(dis[i]==dis[x]+1){
					cnt[i]+=cnt[x];
					continue;
				}
				cnt[i]=cnt[x];
				dis[i]=dis[x]+1;
				q.push(i); 
			}
		}
	}
}
void solve(){
	int l,L=1;
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		nxt[i]=n;
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		while(x[i]-x[L]>l){
			nxt[L]=i-1;
			L++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=1;j<=n;j++){
			if(cnt[j]==2)ans++; 
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
