#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[200004],cnt[200004],bfn[200004],vis[5003][5003],ans;
void bfs(int s){
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	memset(bfn,0,sizeof(bfn));
	queue<pair<int,int>> q;
	q.push({s,1});
	bfn[s]=1,cnt[s]=1;
	while(q.size()){
		auto t=q.front();
		q.pop();
		if(bfn[t.first]!=t.second) continue;
		for(int i=t.first+1;i<=n;i++){
			if(a[i]-a[t.first]>d) break;
			if(vis[t.first][i]||bfn[i]&&bfn[i]!=t.second+1) continue;
			bfn[i]=t.second+1;
			cnt[i]+=cnt[t.first];
			vis[t.first][i]=1;
			q.push({i,t.second+1});
		}
		for(int i=t.first-1;i;i--){
			if(a[t.first]-a[i]>d) break;
			if(vis[t.first][i]||bfn[i]&&bfn[i]!=t.second+1) continue;
			bfn[i]=t.second+1;
			cnt[i]+=cnt[t.first];
			vis[t.first][i]=1;
			q.push({i,t.second+1});
		}
	}
	for(int i=1;i<s;i++){
		if(cnt[i]==2){
			ans++; 
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		cout<<ans<<'\n';
	}
}
