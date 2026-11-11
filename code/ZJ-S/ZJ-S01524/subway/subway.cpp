#include <bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int N=510;
long long w[M];
int c,n,m,d,q,cnt;
set<pair<int,int> > st;
vector<int> sub[N];
vector<pair<int,long long> > stops[M];
vector<long long> query;
long long ans=1ll<<62;
struct info {
	int lt,rt,node;
};
vector<info> request;
vector<long long> finds;
inline void dfs(int curstop,int curline,long long curtime) {
	if(st.count(make_pair(curstop,curline))) {
		return;
	}
	st.insert(make_pair(curstop,curline));
	long long ltime;
	for(int i=0; i<stops[curstop].size(); ++i) {
		if(curline==stops[curstop][i].first) {
			ltime=stops[curstop][i].second;
			break;
		}
	}
	query[curstop]=min(query[curstop],curtime+ltime+w[curstop]);
	for(int i=0; i<stops[curstop].size(); ++i) {
		int nextline=stops[curstop][i].first,dtime=ltime+stops[curstop][i].second;
		if(nextline==curline) continue;
		for(int j=0; j<sub[nextline].size(); ++j) {
			if(sub[nextline][j]!=curstop) {
				dfs(sub[nextline][j],nextline,curtime+dtime);
			}
		}
	}
}
inline bool cmp1(info a,info b) {
	return a.lt<b.lt;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; ++i) {
		cin>>w[i];
	}
	for(int i=1; i<=n; ++i) {
		int u;
		cin>>u;
		for(int j=1; j<=u; ++j) {
			int x,y;
			cin>>x>>y;
			sub[i].push_back(x);
			stops[x].push_back(make_pair(i,y));
		}
	}
	int op=0;
	request.resize(q);
	finds.resize(q);
	while(q--) {
		cin>>request[op].lt>>request[op].rt;
		request[op].node=op++;
	}

	op=0;
	sort(request.begin(),request.end(),cmp1);
	query.resize(m+1);
	for(cnt=1; cnt<=m; ++cnt) {
		fill(query.begin(),query.end(),1ll<<62);
		st.clear();
		for(int i=0; i<stops[cnt].size(); ++i) {
			int nextline=stops[cnt][i].first,dtime=stops[cnt][i].second;
			for(int j=0; j<sub[nextline].size(); ++j) {
				if(sub[nextline][j]!=cnt) {
					st.insert(make_pair(cnt,nextline));
					dfs(sub[nextline][j],nextline,w[cnt]+dtime);
				}
			}
		}
		while(request[op].lt==cnt) {
			finds[request[op].node]=query[request[op].rt];
			++op;
		}
	}
	for(int i=0; i<finds.size(); ++i) {
		cout<<finds[i]<<endl;
	}

	return 0;
}
