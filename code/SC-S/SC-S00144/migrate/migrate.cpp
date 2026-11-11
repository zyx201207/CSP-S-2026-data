#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
//int c,t,n,d,a[N],to[N],len1[N],len2[N],len3[N],siz[N];
//vector<int>g[N];
int c,t,n,d,a[N],to[N],dis[N],ed[N],pyc,type[N];
vector<int>g[N];
struct Tree{
	int Max[N << 2];
	inline void clear(int u = 1,int l = 1,int r = n){
		Max[u] = 0;
		if(l >= r) return;
		int mid = (l + r) >> 1;
		clear(u << 1,l,mid);clear(u << 1 | 1,mid + 1,r);
	}inline void modify(int x,int val,int u = 1,int l = 1,int r = n){
		if(l >= r){Max[u] = max(Max[u],val);return;}
		int mid = (l + r) >> 1;
		if(x <= mid) modify(x,val,u << 1,l,mid);
		else modify(x,val,u << 1 | 1,mid + 1,r);
		Max[u] = max(Max[u << 1],Max[u << 1 | 1]);
	}inline int query(int x,int y,int u = 1,int l = 1,int r = n){
		if(y < l || r < x) return 0;
		if(x <= l && r <= y) return Max[u];
		int mid = (l + r) >> 1;
		return max(query(x,y,u << 1,l,mid),query(x,y,u << 1 | 1,mid + 1,r));
	} 
}Furina;
inline void solve(int u){
	for(int i = 0;i <= n;++i) ed[i] = 0,dis[i] = 0,to[i] = 0,type[i] = 0;
	Furina.clear();
	int pos = n;
	for(int i = u + 1;i <= n;++i){
		to[i] = lower_bound(a + u,a + n + 1,a[i] - d) - a;
		if(to[i] == i){pos = i;break;}
		dis[i] = dis[to[i]] + 1;ed[dis[i]] = i;
		g[to[i]].emplace_back(i);
	}for(int i = u;i <= pos;++i){
		int ty = Furina.query(to[i],ed[dis[to[i]]]),len = ed[dis[to[i]]] - to[i] + 1;
		type[i] = ty + (len - 1);
		if(type[i] == 1) ++pyc;
		Furina.modify(i,type[i]);
	}
}signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;pyc = 0;
//		for(int i = 1;i <= n;++i) cin >> a[i],g[i].clear(),len1[i] = len2[i] = len3[i] = 0,siz[i] = 1;
//		for(int i = 1;i <= n;++i){
//			to[i] = upper_bound(a + 1,a + 1 + n,a[i] + d) - a - 1;
//			if(to[i] == i) continue;
//			g[to[i]].emplace_back(i);
//			siz[to[i]] += siz[i];
//		}for(int i = n;i >= 1;--i){
//			if(to[i] == i){
//				len1[i] = 1;
//				len3[i] = 0;
//			}else{
//				len1[i] = len1[to[i]] + 1;
//				len3[i] = len3[to[i]] + max(0ll,to[i] - i - 1);			
//			}if(g[i].size() > 1) len1[i] = 0,len3[i] = 0;
//		}for(int i = 1;i <= n;++i){
//			if(g[i].size() == 1) len2[i] = len2[g[i][0]] + 1;
//			else len2[i] = 0;
//		}int pyc = 0;
//		for(int i = 1;i <= n;++i){
//			if(g[i].size() == 2){
//				pyc += (len1[to[i]] + 1 + len3[to[i]] + max(0ll,to[i] - i - 1)) * len2[g[i][1]];
//			}
//		}for(int i = 1;i <= n;++i){
//			int j = to[i],k = to[j];
//			pyc += max(0ll,min(j - i - 1,k - j - 1));
//		}cout << pyc << "\n";
		for(int i = 1;i <= n;++i){
			cin >> a[i];
		}for(int i = 1;i <= n;++i) solve(i);
		cout << pyc << "\n";			
	}
	return 0;
}