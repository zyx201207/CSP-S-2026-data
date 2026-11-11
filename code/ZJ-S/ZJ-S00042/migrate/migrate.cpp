#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
int n;ll d,x[N];
const int inf=0x3f3f3f3f;
namespace subtask1{
	int dis[10005],num[10005];bitset<10005> vis;
	int ls[10005],rs[10005],rt,cnt;
	vector<pair<int,int> >g[10005];
	void build(int &x=rt,int l=1,int r=n){
		if(l==r)return void(x=l);
		x=++cnt;
		int mid=l+r>>1;
		build(ls[x],l,mid);
		build(rs[x],mid+1,r);
		g[x].emplace_back(ls[x],0);
		g[x].emplace_back(rs[x],0);
		return;
	}
	void addedge(int p,int l,int r,int x=rt,int nowl=1,int nowr=n){
		if(l<=nowl&&nowr<=r)return void(g[p].emplace_back(x,1));
		int mid=nowl+nowr>>1;
		if(l<=mid)addedge(p,l,r,ls[x],nowl,mid);
		if(mid<r)addedge(p,l,r,rs[x],mid+1,nowr);
		return;
	}
	int dijkstra(int s){
		for(int i=1;i<=cnt;++i)dis[i]=inf,num[i]=0,vis[i]=false;
		dis[s]=0;num[s]=1;
		priority_queue<pair<int,int> >q;
		q.push({0,s});
		while(!q.empty()){
			int x=q.top().second;q.pop();
			if(vis[x])continue;
			vis[x]=true;
			for(vector<pair<int,int> >::iterator it=g[x].begin();it!=g[x].end();++it){
				int y=it->first,w=it->second;
				if(!vis[y]){
					if(dis[x]+w<dis[y]){
						dis[y]=dis[x]+w;
						num[y]=num[x];
						q.push({-dis[y],y});
					}
					else if(dis[x]+w==dis[y]){
						num[y]+=num[x];
					}
				}
			}
		}
		int ans=0;
		for(int i=s;i<=n;++i)ans+=(num[i]==2);
//		for(int i=s;i<=n;++i)cout<<s<<"->"<<i<<" "<<num[i]<<'\n';
		return ans;
	}
	void solve(){
		cnt=n;
		build();
		for(int i=1,j=1;i<n;++i){
			while(j<n&&x[j+1]-x[i]<=d)++j;
			addedge(i,i+1,j);
		}
//		for(int i=1;i<=cnt;++i)
//			for(vector<pair<int,int> >::iterator it=g[i].begin();it!=g[i].end();++it)
//				cout<<i<<"->"<<it->first <<'\n';
		int res=0;
		for(int s=1;s<=n;++s)res+=dijkstra(s);
		cout<<res<<'\n';
		for(int i=1;i<=cnt;++i)ls[i]=rs[i]=0,g[i].clear();
		rt=cnt=0;
		return;
	}
}
namespace subtask2{
	vector<int>g[305];
	int dis[305],num[305];
	bitset<305>vis;
	int dijkstra(int s){
		for(int i=1;i<=n;++i)dis[i]=inf,num[i]=0,vis[i]=false;
		priority_queue<pair<int,int> >q;
		q.push({0,s});dis[s]=0;num[s]=1;
		while(!q.empty()){
			int x=q.top().second;q.pop();
			if(vis[x])continue;
			vis[x]=true;
			for(int y:g[x]){
				if(!vis[y]){
					if(dis[x]+1<dis[y]){
						dis[y]=dis[x]+1;
						num[y]=num[x];
						q.push({-dis[y],y});
					}
					else{
						num[y]+=num[x];
					}
				}
			}
		}
		int ans=0;
		for(int i=s;i<=n;++i)ans+=(num[i]==2);//,cout<<s<<"->"<<i<<" "<<num[i]<<'\n';
		return ans;
	}
	void solve(){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(x[j]-x[i]>d)break;
				g[i].emplace_back(j);
//				cout<<i<<' '<<j<<'\n';
			}
		}
		int res=0;
		for(int s=1;s<=n;++s)res+=dijkstra(s);
		cout<<res<<'\n';
		for(int i=1;i<=n;++i)g[i].clear();
		return;
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>x[i];
	if(n<=300)return void(subtask2::solve());
	if(n<=5000)return void(subtask1::solve());
	//40pts
	subtask1::solve();
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int _=1,c;cin>>c>>_;
	while(_--)solve();
	return 0;
}
/*
华风夏韵，洛水天依！
 freopen("migrate.in","r",stdin);
出两道图是什么意思？
输麻了
 
*/
