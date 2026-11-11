#include<bits/stdc++.h>
using namespace std;
const int N1 = 105;
const int N = 1e6+5;
vector<int> edg[N];
int dep[N],fa[N],dis[N],s[N],q[N],siz,a,b,k;
pair<int,int> mx[N];
//int dp[N1][N1],rem[N1];rp++
//bool vis[N];
void dfs(int now,int f){
	dep[now] = dep[f]+1,fa[now] = f,mx[now] = make_pair(0,now);
	pair<int,int> mx2 = make_pair(0,now);
	for(auto& i : edg[now]){
		if(i==f) continue;
		dfs(i,now);
		auto nmx = mx[i];
		nmx.first++;
		if(nmx.first>mx[now].first) swap(mx[now],nmx);
		if(nmx.first>mx2.first) swap(nmx,mx2);
	}
	if(mx[now].first+mx2.first>siz) siz = mx[now].first+mx2.first,a = mx[now].second,b = mx2.second;
}
void dfs2(int now,int f){
	fa[now] = f,dep[now] = dep[f]+1,dis[now] = 0;
	for(auto& i : edg[now]){
		if(i==f) continue;
		dfs2(i,now),dis[now] = max(dis[now],dis[i]+1);
	}
}
//void dfs3(int now,int f){300pts+
//	dis[now] = 0,fa[now] = f;
//	int sn = 0;
//	for(auto& i : edg[now]){
//		if(i==f) continue;
//		dfs3(i,now),dis[now] = max(dis[now],dis[i]+1);
//		if(s[i]>s[sn]) sn = i;
//	}
//	int mxd = 0;
//	for(auto& i : edg[now]){
//		if(i==f||i==sn) continue;
//		mxd = max(mxd,dis[i]+1);
//	}
//	vector<int> pre(s[now]);
//	dp[now][1] = dis[now];
//	for(int i=2;i<=s[sn]+1;i++) dp[now][i] = dp[sn][i-1];
//	s[now] = s[sn]+1;
//	for(auto& i : edg[now]){
//		if(i==f||i==sn) continue;
//		for(int j=1;j<=s[now];j++) rem[j] = dp[now][j];
//		for(int j=1;j<=s[now];j++) dp[now][j] = max(dp[now][j],dis[i]+1);
//		for(int j=1;j<=s[i];j++){
//			dp[now][s[now]+j] = 1e9;
//			for(int l=1;l<=s[now];l++) dp[now][l+j] = min(dp[now][l+j],max(rem[l],dp[i][j]));
//		}
//		s[now]+=s[i];
//	}
//}
//void dfs4(int now,int f){
//	vis[now] = true;
//	for(auto& i : edg[now]){
//		if(i==f) continue;
//		dfs4(i,now);
//	}
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		cin>>n>>k;
		for(int i=1;i<=n;i++) edg[i].clear();
		for(int i=1,u,v;i<n;i++) cin>>u>>v,edg[u].emplace_back(v),edg[v].emplace_back(u);
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(k==n-1){
			cout<<"1\n";
			continue;
		}
		if(c==13||c==14){
			if(k>=n/2) cout<<"1\n";
			else{
				int len = n/2;
				int ans = n+1;
				for(int i=0;i*3+k<=len;i++) ans = min(ans,max(i,len-i*3-k));
				cout<<ans+1<<'\n';
			}
			continue;
		}
//		if(c<=6){QWQQWQQWQ
//			dfs3(1,0);
//			int ans = 1e9;
//			for(int i=2;i<=n;i++) for(int j=1;j<i;j++){
//				int ql = 1,qr = 0;
//				q[++qr] = i,q[++qr] = j;
//				for(int l=1;l<=n;l++) vis[l] = false;
//				dfs4(i,fa[i]),dfs4(j,fa[j]),dis[i] = dis[j] = 0;
//				int nowans = 0;
//				while(ql<=qr){
//					int now = q[ql++];
//					nowans = max(nowans,dis[now]);
//					for(auto& l : edg[now]){
//						if(vis[l]) continue;
//						vis[l] = true;
//						dis[l] = dis[now]+1;
//						q[++qr] = l;
//					}
//				}
//				cout<<i<<' '<<j<<' '<<nowans<<'\n';
//				for(int l=1;l<k;l++) ans = min(ans,max({nowans,dp[i][l],dp[j][k-l]}));
//			}
//			for(int i=1;i<=n;i++){
//				int ql = 1,qr = 0;
//				q[++qr] = i;
//				for(int l=1;l<=n;l++) vis[l] = false;
//				dfs4(i,fa[i]),dis[i] = 0;
//				int nowans = 0;
//				while(ql<=qr){
//					int now = q[ql++];
//					nowans = max(nowans,dis[now]);
//					for(auto& l : edg[now]){
//						if(vis[l]) continue;
//						vis[l] = true;
//						dis[l] = dis[now]+1;
//						q[++qr] = l;
//					}
//				}
//				ans = min(ans,max(nowans,dp[i][k]));
//			}
//			cout<<ans<<'\n';
//			continue;
//		}
		siz = 0,dfs(1,0);
		int mid = a;
		for(int i=1;i<=(siz+1)/2;i++) mid = fa[mid];
		dfs2(mid,0);
		int cnt = 0;
		for(auto& i : edg[mid]) if(dis[i]+1>=siz/2) cnt++;
		if(cnt>2){
			priority_queue<pair<int,int> > q;
			q.emplace(dis[mid]+1,mid);
			while(k--){
				auto now = q.top().second;
				q.pop();
				for(auto& i : edg[now]){
					if(i==fa[i]) continue;
					q.emplace(dis[i]+1,i);
				}
			}
			cout<<q.top().first<<'\n';
			continue;
		}
	}
	return 0;
}
