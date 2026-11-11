#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
	int Line,Pos;
	bool operator < (const node &temp)const {
		if(Line!=temp.Line) return Line<temp.Line;
		return Pos<temp.Pos;
	}
};
map<int,node> mp1;
map<node,int> mp2;
int len;
int c,n,m,d,q;
int w[500500];
int a[500500],t[500500];
vector<pair<int,int> > g[10000005];
struct NODE {
	int pos,len;
	bool operator < (const NODE &temp)const {
		return len > temp.len;
	}
};
bool cnt[10000005];
int bfs(int S,int T) {
	for(int i = 1;i <= len;i++) cnt[i]=0;
	priority_queue<NODE> pq;
	pq.push({mp2[{0,S}],0});
	while(!pq.empty()) {
		NODE now = pq.top();
		pq.pop();
		if(mp1[now.pos].Line==0&&mp1[now.pos].Pos==T) return now.len;
		if(cnt[now.pos]) continue;
		cnt[now.pos]=1;
		for(int i = 0;i < g[now.pos].size();i++) {
			int v = g[now.pos][i].first;
			int w = g[now.pos][i].second;
			pq.push({v,now.len+w});
		}
	}
	return -1;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) {
		cin >> w[i];
		mp1[++len]={0,i};
		mp2[{0,i}]=len;
	}
	for(int i = 1;i <= n;i++) {
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++) {
			cin >> a[j] >> t[j];
			mp1[++len]={i,a[j]};
			mp2[{i,a[j]}]=len;
			g[mp2[{0,a[j]}]].push_back({mp2[{i,a[j]}],t[j]});
			g[mp2[{i,a[j]}]].push_back({mp2[{0,a[j]}],t[j]});
		}
		for(int j = 1;j < k;j++) {
			g[mp2[{i,a[j]}]].push_back({mp2[{i,a[j+1]}],0});
			g[mp2[{i,a[j+1]}]].push_back({mp2[{i,a[j]}],0});
		}
	}
	while(q--) {
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+bfs(x,y) << endl;
	}
	return 0;
}
