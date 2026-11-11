#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FILE "migrate"
#define JUDGE
const int N=5e3+5;
int a[N];
int c,n,d;
int dis[N],num[N];
int bfs(int s){
	memset(dis,0x3f,sizeof dis);
	memset(num,0,sizeof num);
	queue<int> q;
	dis[s]=0,q.push(s),num[s]=1;
	while(q.size()){
		int u=q.front();q.pop();
		for(int v=u+1; v<=n; v++){
			if(a[v]-a[u]>d) break;
			if(dis[v]>dis[u]+1){
				num[v]=num[u];
				dis[v]=dis[u]+1;
				q.push(v);
			}else if(dis[v]==dis[u]+1){
				num[v]+=num[u];
			}
		}
	}
	int ans=0;
	for(int i=s+1; i<=n; i++){
		ans+=(num[i]==2);
	}
//	cout<<'\n';
//	for(int i=1; i<=m; i++){
//		cout<<dis[i]<<' ';
//	}
//	cout<<'\n';
	return ans;
}
signed main(){
	#ifdef JUDGE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
	#endif
	int t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1; i<=n; i++){
			ans+=bfs(i);
		}
		cout<<ans<<'\n';
	}
	#ifdef JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}
/*
空悲切 
*/