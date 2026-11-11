//migrate
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+9;
const int INF=0x3f3f3f3f3f3f3f3f;
int testnum,ntest;
int n,md;
vector<int> d[N];
int x[N];
int dis[N];
bool ok[N];
int cnt[N];
struct Node{
	int u,d;
	bool operator<(const Node&p)const{
		if(d>p.d) return true;
		return false;
	}
};
void add(int u,int v){
	d[u].push_back(v);
}
void bfs(int st){
	for(int i=1;i<=n;i++) dis[i]=INF,ok[i]=0,cnt[i]=0;
	queue<int> q;
	q.push(st);
	dis[st]=0; cnt[st]=1;
	while(q.empty()==false){
		int u=q.front(); q.pop();
		for(int i=0;i<d[u].size();i++){
			int v=d[u][i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
			}
			else if(dis[u]+1==dis[v]){
				cnt[v]+=cnt[u];
			}
		}
	}
}
void solve(){
	cin>>n>>md;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>x[i],d[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=md) add(i,j),add(j,i);
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<endl;
}
void solve1112(){
	cin>>n>>md;
	for(int i=1;i<=n;i++) cin>>x[i];
	int num=md/(x[2]-x[1]);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i+2*num-1<=n) ans++;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>testnum>>ntest;
	if(testnum==11||testnum==12) solve1112();
	else{
		while(ntest--) solve();
	}
	return 0;
}
