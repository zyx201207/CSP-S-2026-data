#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
const int maxnn=1e5+7;
const int inf=1e9+7;
const int maxn=15;
vector<int> edge[maxnn];
bool check(int x) {
	int L=x,R=n/2+1-x;
	if((R-L-(k-1))/2+1<=x) return 1;
	return 0;
}
bool sel[maxn],vis[maxnn];
int dis[maxnn];
void add(int x) {
	for(int y:edge[x]) {
		if(!vis[y] && sel[y]) {
			vis[y]=1;
			add(y);
		}
	}
}
int fin;
int sol() {
	int num=0;
	for(int i=1; i<=n; i++) vis[i]=0;
	for(int i=1; i<=n; i++) {
		if(!vis[i] && sel[i]) {
			vis[i]=1;
			num++;
			add(i);
		}
	}
	if(num>2) return inf;
	queue<int> que;
	for(int i=1; i<=n; i++) {
		vis[i]=0;
		if(sel[i]) {
			que.push(i);
			dis[i]=0;
		} else dis[i]=inf;
	}
	while(que.size()) {
		int u=que.front();
		que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:edge[u]) {
			if(sel[v]) continue;
			if(dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				que.push(v);
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++)
		ans=max(ans,dis[i]);
	return ans;
}
void dfs(int x,int now) {
	if(now>=k) {
		fin=min(fin,sol());
		return;
	}
	if(x>n) return;
	dfs(x+1,now);
	sel[x]=1;
	dfs(x+1,now+1);
	sel[x]=0;
}
void fd(int x,int fa) {
	for(int y:edge[x]) {
		if(y==fa) continue;
		dis[y]=dis[x]+1;
		fd(y,x);
	}
}
int work() {
	for(int i=1; i<=n; i++) dis[i]=0;
	fd(1,1);
	int mx=0,l=0;
	for(int i=1; i<=n; i++) {
		if(dis[i]>mx) {
			mx=dis[i];
			l=i;
		}
		dis[i]=0;
	}
	fd(l,l);
	mx=0;
	for(int i=1; i<=n; i++)
		mx=max(mx,dis[i]);
	return (mx+2)/3;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(c<=3) {
			fin=inf;
			dfs(1,0);
			cout<<fin<<"\n";
		} else if(c==13 || c==14) {
			if(k==n) cout<<"0\n";
			else if(k>=n/2) cout<<"1\n";
			else {
				int l=1,r=n/2;
				while(l<r) {
					int mid=l+r>>1;
					if(check(mid)) r=mid;
					else l=mid+1;
				}
				cout<<l<<"\n";
			}
		} else if(c==7 || c==11 || c==12) 
			cout<<work()<<"\n";
		for(int i=1; i<=n; i++)
			edge[i].clear();
	}
	return 0;
}