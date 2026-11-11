#include<bits/stdc++.h>
using namespace std;
vector<long long>g[1000005];
queue<long long>d;
long long n,k,vis[1000006],dis[1000006],cvis[1000006];
long long bfs(){
	while(d.size()){
		long long u=d.front();
		d.pop(); 
		for(long long v:g[u]){
			if(vis[v]){
				continue;
			}
			dis[v]=min(dis[v],dis[u]+1);
			vis[v]=1;
			d.push(v);
		}
	}
	long long an=0;
	for(long long i=1;i<=n;i++){
//		cout<<dis[i]<<' ';
		an=max(an,dis[i]);
	}
//	cout<<'\n';
	return an;
}
void dfs(long long u){
	cvis[u]=1;
	for(long long v:g[u]){
		if(cvis[v]||vis[v]==0){
			continue;
		}
		dfs(v);
	}
	return;
}
bool check(){
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		if(cvis[i]==0&&vis[i]){
			dfs(i);
			cnt++;
		}
	}
//	cout<<cnt<<' ';
	return (cnt<=2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(c>=0&&c<=3){
			for(long long i=1;i<=n;i++){
				g[i].clear();
			}
			for(long long i=1;i<=n-1;i++){
				long long u,v;
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			long long an=1e18;
			for(long long i=0;i<(1<<n);i++){
				long long cnt=0;
				for(long long j=0;j<n;j++){
					if((1<<j)&i){
						cnt++;
					}
				}
				if(cnt!=k){
					continue;
				}
				for(long long j=1;j<=n;j++){
					vis[j]=0;
					dis[j]=1e18;
					cvis[j]=0;
				}
				while(d.size()){
					d.pop();
				}
				for(long long j=0;j<n;j++){
					if((1<<j)&i){
						d.push(j+1);
						vis[j+1]=1;
						dis[j+1]=0;
					}
				}
				if(check()==0){
					continue;
				}
//				if(bfs()==1){
//					cout<<i<<'\n';
//				}
				an=min(an,bfs());
			}
			cout<<an<<'\n';
		}else if(c>=13&&c<=14){
			long long m=n/2;
			if(k<=(m+2)/3){
				long long len=(m+k-1)/k;
				len/=2;
				cout<<len<<'\n';
			}else if(k>(m+2)/3&&k<n){
				cout<<1<<'\n'; 
			}else{
				cout<<0<<'\n';
			}
		}
	}
	return 0;
}
//代码敲慢一点！！！
//注意freopen
//注意数组大小
//注意函数返回值
//注意取模
//恰.好

