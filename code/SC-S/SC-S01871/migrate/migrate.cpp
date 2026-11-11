#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long m,n,a[N],dis[N],cnt[N],ans=0;
queue<int> q;
void bfs(){
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=x+1;i<=n;i++){
			if(a[i]-a[x]>m) break;
			if(dis[i]==0x3f3f3f3f3f3f3f3f){
				dis[i]=dis[x]+1,cnt[i]+=cnt[x];
				q.push(i);
			}
			else if(dis[i]==dis[x]+1) cnt[i]+=cnt[x]; 
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]==2)
			ans++;
	}
}
void solve(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f3f3f3f3f,cnt[i]=0; 
		dis[i]=0;cnt[i]=1;
		q.push(i);
		bfs();
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T,c;cin>>c>>T;
	while(T--) solve();
} 