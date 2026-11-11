#include<bits/stdc++.h>//bao li   WA
using namespace std;
int c,n,m,d,q;
struct line{
	int n;
	vector<int> s;
	vector<int> t;
};
vector<line> l;
struct station{
	int t0;
	int nl;
	vector<int> li;
	vector<int> tj;//time to go to j
};
vector<station> s; 
vector<bool> visit;
int dfs(int st,int en){
	if(st==en)return 0;
	if(s[st].tj[en]!=0)return s[st].tj[en];
	for(int i=0;i<s[st].nl;i++){
		line tl=l[s[st].li[i]];
		for(int j=0;j<tl.n;j++){
			int dest=tl.s[j];
			if(dest==st)continue;
			if(!visit[dest]){
				visit[dest]=1;
				int newl=tl.t[st]+tl.t[dest]+dfs(dest,en);
				if(s[st].tj[en]==0)s[st].tj[en]=newl;
				else s[st].tj[en]=min(s[st].tj[en],newl);
				visit[dest]=0;
			}
		}
	}
	s[en].tj[st]=s[st].tj[en];
	return s[st].tj[en];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	l.resize(n+1);
	s.resize(m+1);
	visit.resize(m+1);
	for(int i=1;i<=m;i++){
		cin>>s[i].t0;
		s[i].nl=0;
		s[i].tj.resize(m+1);
	}
	int a,b;
	for(int i=1;i<=n;i++){
		cin>>l[i].n;
		l[i].t.resize(m+1);
		for(int j=0;j<l[i].n;j++){
			cin>>a>>b;
			l[i].s.push_back(a);
			l[i].t[a]=b;
			s[a].nl++;
			s[a].li.push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dfs(i,j);
		}
	}
	while(q--){
		cin>>a>>b;
		visit.clear();
		visit[a]=1;
		cout<<dfs(a,b)+s[a].t0+s[b].t0<<endl;
		visit[a]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<i<<" "<<j<<" "<<dfs(i,j)<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
