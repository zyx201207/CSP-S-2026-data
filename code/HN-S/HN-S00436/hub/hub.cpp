#include<bits/stdc++.h>
using namespace std;
void file_init(){
#ifdef LOCAL
	freopen("hub1.in","r",stdin);
	freopen("hub.out","w",stdout);
#else
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	return;
}
void fast_read(){
#ifndef cin
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	return;
}
int n,k;
const int N=1e6+10;
vector<int>g[N];
void input(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(n==2){
		cout<<'0'<<'\n';
	}
	return;
}
int s,t;
int dep[N];
int fa[N];
void dfs(int now,int lst){
	fa[now]=lst;
	if(dep[now]>dep[t]){
		t=now;
	}
	for(int nxt:g[now]){
		if(nxt==lst){
			continue;
		}
		dep[nxt]=dep[now]+1;
		dfs(nxt,now);
	}
	return;
}
int rt;
void init(){
	t=1;
	dep[1]=0;
	dfs(1,1);
	s=t;
	dep[s]=0;
	dfs(s,s);
	int cnt=dep[t]>>1;
	rt=t;
	while(cnt--){
		rt=fa[rt];
	}
	dep[rt]=0;
	return;
}
int mid;
namespace lift{
	int lg[N];
	void pre_lg(){
		lg[0]=-1;
		for(int i=1;i<=n;i++){
			lg[i]=lg[i>>1]+1;
		}
		return;
	}
	vector<int>l;
	const int M=20;
	int f[N][M];
	void init(int now){
		for(int i=1;i<=lg[dep[now]];i++){
			f[now][i]=f[f[now][i-1]][i-1];
		}
		for(int nxt:g[now]){
			if(nxt==f[now][0]){
				continue;
			}
			dep[nxt]=dep[now]+1;
			f[nxt][0]=now;
			init(nxt);
		}
		if(g[now].size()==1){
			l.push_back(now);
		}
		return;
	}
	bool cmp(int x,int y){
		return dep[x]<dep[y];
	}
	void adjust(){
		sort(l.begin(),l.end(),cmp);
		return;
	}
	vector<int>mus;
	bool mark[N];
	int req;
	int dfs(int now){
		int mx=0;
		for(int nxt:g[now]){
			if(nxt==f[now][0]){
				continue;
			}
			mx=max(mx,dfs(nxt)+1);
		}
		if(mx==mid&&now!=rt){
			mus.push_back(now);
			mark[now]=true;
			mx=0;
		}
		return mx;
	}
	void jump(){
		req=dep[t];
		mus.clear();
		for(int i=1;i<=n;i++){
			mark[i]=false;
		}
		for(int i:l){
			if(dep[i]<=mid){
				req=min(req,mid-dep[i]);
			}
		}
		dfs(rt);
		return;
	}
	int mndis(int now){
		if(mark[now]==true){
			return 0;
		}
		int val=0;
		for(int nxt:g[now]){
			if(nxt==f[now][0]){
				continue;
			}
			val=max(val,mndis(nxt)+1);
		}
		return val;
	}
	struct heap{
		int id;
		friend bool operator<(heap x,heap y){
			return dep[x.id]<dep[y.id];
		}
	};
	priority_queue<heap>q;
	int solve(){
		int ans=0;
		while(q.empty()==false){
			q.pop();
		}
		int mn=dep[t];
		for(int i:mus){
			ans++;
			q.push({i});
			mn=min(mn,dep[i]);
		}
		while(q.size()>2){
			int now=q.top().id;
			q.pop();
			if(mark[f[now][0]]==false){
				ans++;
				mark[f[now][0]]=true;
				q.push({f[now][0]});
				mn=min(mn,dep[f[now][0]]);
			}
		}
		return ans+max(0,mn-req);
	}
}
bool check(){
	lift::jump();
	if(lift::mndis(rt)>mid){
		return false;
	}
	return lift::solve()<=k;
}
int ans;
void solve(){
	int lt=0,rt=dep[t];
	while(lt<=rt){
		mid=(lt+rt)>>1;
		if(check()){
			rt=mid-1;
			ans=mid;
		}else{
			lt=mid+1;
		}
	}
	return;
}
void reset(){
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	lift::l.clear();
	ans=-1;
	return;
}
int main(){
	file_init();
	fast_read();
	int c,t;
	cin>>c>>t;
	while(t--){
		reset();
		input();
		if(n==2){
			continue;
		}
		init();
		lift::pre_lg();
		lift::init(rt);
		solve();
		cout<<ans<<'\n';
	}
	return 0;
}
