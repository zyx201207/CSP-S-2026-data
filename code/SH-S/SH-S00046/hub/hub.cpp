#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,t,n,k,dis[20],ans;
bool book[20];
vector<int> E[20];
int rest(int x){
	if (!x) return 0;
	memset(book,0,sizeof book);
	int u=log2(x&-x)+1;
//	cout<<x<<" "<<u<<"\n";
	x^=(1<<u-1);
	book[u]=1;
	queue<int> q;
	q.push(u);
	while (q.size()){
		u=q.front();q.pop();
		for (auto v:E[u]){
			if (!book[v]&&(x&(1<<v-1))){
				book[v]=1;
				q.push(v);
				x^=(1<<v-1);
			}
		}
	}
	return x;
}
int bfs(int x){
	int res=0;
	memset(book,0,sizeof book);
	memset(dis,0,sizeof dis);
	queue<int> q;
	for (int i = 1; i <= n; i++){
		if (x&(1<<i-1)){
			q.push(i);
			book[i]=1;
		}
	} 
	while (q.size()){
		int u=q.front();q.pop();
		res=max(res,dis[u]);
		for (auto v:E[u]){
			if (!book[v]){
				book[v]=1;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>k;
		ans=INT_MAX;
		for (int i = 1; i <= n; i++) E[i].clear();
		for (int i = 1; i < n; i++){
			int x,y;
			cin>>x>>y;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		for (int i = 0; i < (1<<n); i++){
			if (__builtin_popcount(i)!=k) continue;
			for (int j = i; j; j=(j-1)&i){
				int k=i^j;
				if (rest(j)||rest(k)) continue;
//				cout<<i<<"\n";
//				cout<<"!!!\n";
				ans=min(ans,bfs(i));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
*/
