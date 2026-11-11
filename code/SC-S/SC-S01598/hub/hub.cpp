#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e6+10;
int c,t;
int n,k;
vector <int> G[N];
int nd[N];
bool vis[N];
int depth[N],fa[N];
void init(int x,int last,int dep){
	depth[x]=dep;
	fa[x]=last;
	for (int to:G[x]){
		if (to==last) continue;
		init(to,x,dep+1);
	}
}
int cnt[N];
void dfs(int x,int last,int limit){
	int maxnd=0;
	for (int to:G[x]){
		if (to==last) continue;
		dfs(to,x,limit);
		maxnd=max(maxnd,nd[to]);
		cnt[x]+=cnt[to];
	}
	if (maxnd==limit) vis[x]=1;
	if (vis[x]) nd[x]=0;
	else nd[x]=maxnd+1;
	cnt[x]+=vis[x];
}
bool key_pts[N];
vector <int> ct,pos;
void get_key_pts(int x,int last){
	int ch=0;
	for (int to:G[x]){
		if (to==last) continue;
		get_key_pts(to,x);
		if (cnt[to]) ch++;
	}
	bool has_key=(cnt[1]-cnt[x])!=0;
	if ((ch>=2&&has_key)||ch>=3||vis[x]) key_pts[x]=1;
}
void collect_val(int x,int last,int last_pos){
	if (key_pts[x]){
		if (last_pos) ct.push_back(depth[last]-depth[last_pos]);
		else pos.push_back(x);
		last_pos=x;
	}
	for (int to:G[x]){
		if (to==last) continue;
		collect_val(to,x,last_pos);
	}
}
int get_dis(int x,int y){
	if (depth[x]<depth[y]) swap(x,y);
	int cntnow=0;
	while(x&&depth[x]>depth[y]){
		x=fa[x];
		cntnow++;
	}
	while(x!=y){
		x=fa[x],y=fa[y];
		cntnow+=2;
	}
	return cntnow-1;
}
bool check(int mid){
	memset(vis,0,sizeof vis);
	memset(nd,0,sizeof nd);
	memset(cnt,0,sizeof cnt);
	memset(key_pts,0,sizeof key_pts);
//	cout << mid << ':' << endl;
	ct.clear();
	pos.clear();
	dfs(1,0,mid);
	get_key_pts(1,0);
	collect_val(1,0,0);
//	cout << pos.size() << endl; 
	if (pos.size()==2){
		ct.push_back(get_dis(pos[0],pos[1]));
	}
	sort(ct.begin(),ct.end());
	int cntall=0;
//	cout << "key_pts:" << endl;
	for (int i=1;i<=n;i++){
		if (key_pts[i]){
			cntall++;
	//		cout << i << ' ';
		}
	}
//	cout << endl;
///	cout << "ct:" << endl;
//	for (int to:ct) cout << to << ' ';
//	cout << endl;
	for (int i=0;i<(int)ct.size()-1;i++) cntall+=ct[i];
	return cntall<=k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for (int i=1;i<=n;i++) G[i].clear();
		for (int i=1,u,v;i<n;i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		init(1,0,1);
	//	cout << "OK" << endl;
		int l=0,r=n,mid,ans=n;
		while(l<=r){
			mid=(l+r)>>1;
			if (check(mid)){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		cout<< ans << '\n';
	}


	return 0;
}
/*
0 1
16 5
1 2
2 3
2 4
4 5
4 8
8 9
5 6
6 7
1 10
10 12
1 11
11 13
13 15
13 14
14 16

0 1
11 3
1 2
2 3
3 4
4 5
1 6
6 7
6 8
8 9
9 10
6 11

*/
