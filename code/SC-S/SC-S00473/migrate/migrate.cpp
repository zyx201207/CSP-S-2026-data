#include<bits/stdc++.h>
using namespace std;
long long a[2000006],dp[2000006],vis[2000006],dis[2000006];
vector<long long>g[2000006];
long long n,d;
long long bfs(long long s){
	queue<long long>d;
	d.push(s);
	dp[s]=1;
	dis[s]=0;
	while(d.size()){
		long long u=d.front();
		d.pop();
//		if(s==1&&n==5){
//			cout<<u<<' ';
//		}
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(long long v:g[u]){
			if(dis[v]==0||dis[v]==dis[u]+1){
				dp[v]+=dp[u];
				d.push(v);
				dis[v]=dis[u]+1;
			}
		}
	}
	long long an=0;
	for(long long i=1;i<=n;i++){
//		cout<<dp[i]<<' ';
		if(dp[i]==2){
			an++;
		}
	}
//	cout<<'\n';
	return an;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=0&&c<=10){
			for(long long i=1;i<=n;i++){
				g[i].clear();
			}
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d){
						g[i].push_back(j);
					}
				}
			}
			long long an=0;
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					dp[j]=vis[j]=dis[j]=0;
				}
				an+=bfs(i);
			}
			cout<<an<<'\n';
		}else if(c>=11&&c<=12){
			long long ch=a[2]-a[1];
			d/=ch;
			long long an=min(n,2*d-1)-d;
			cout<<an<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
//代码敲慢一点！！！
//注意freopen
//注意数组大小
//注意函数返回值
//注意取模
//本.题.包.含.多.组.测.试.数.据!!!!!!
//.恰.好!!!
