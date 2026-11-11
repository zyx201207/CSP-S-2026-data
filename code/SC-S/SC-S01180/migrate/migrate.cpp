#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+7;
long long C,T,n,d,x[N],ans,path[N],dep[N],vis[N];
vector<long long> s[N];

void bfs(long long asd){
	queue<pair<long long,long long>> q;
	q.push({asd,1});
	dep[asd]=1,path[asd]=1;
	while(q.size()){
		auto now=q.front();
		q.pop();
		long long u=now.first,step=now.second;
//		cout<<u<<' ';
//		if(dep[u]>step) dep[u]=step,path[u]=0;
//		if(step==dep[u]) path[u]++;
		for(int v:s[u]){
			if(path[u]<=2) q.push({v,step+1}),vis[u]=1;
			if(dep[v]>step+1) dep[v]=step+1,path[v]=0;
			if(step+1==dep[v]) path[v]++;
		}
	}
}

void solve1(){
	ans=0;
	cin>>n>>d;
	for(long long i=1;i<=n;i++) cin>>x[i],s[i].clear();
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d) s[i].push_back(j);
			else break;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++) dep[j]=1e9,path[j]=0,vis[i]=0;
		bfs(i);
		for(long long j=1;j<=n;j++) if(path[j]==2) ans++;
		cout<<i<<":";for(int j=1;j<=n;j++){
			cout<<path[j]<<' ';
		}cout<<'\n';
	}
	cout<<ans<<'\n';
//	for(long long i=1;i<=n;i++){
//		cout<<i<<":";
//		for(long long j:s[i]){
//			cout<<j<<' ';
//		}
//		cout<<'\n';
//	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	if(C<=10)while(T--)solve1();
	return 0;
}