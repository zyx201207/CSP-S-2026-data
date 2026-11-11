#include <bits/stdc++.h>
using namespace std;
template<typename T> using vec=vector<T>;
constexpr long long INF=0x1fffffffffffffff;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vec<long long> w(m);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	vec<vec<int>> l(m,vec<int>());
	vec<vec<long long>> t(m,vec<long long>());
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a;
			long long s;
			cin>>a>>s;
			a--;
			l[a].push_back(i);
			t[a].push_back(s);
		}
	}
	vec<vec<long long>> mp(n,vec<long long>(n,INF));
	for(int i=0;i<n;i++){
		mp[i][i]=0;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<l[i].size();j++){
			for(int k=0;k<l[i].size();k++){
				mp[l[i][j]][l[i][k]]=min(mp[l[i][j]][l[i][k]],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mp[i][j]==INF) continue;
			for(int k=0;k<n;k++){
				if(mp[j][k]==INF) continue;
				mp[i][k]=min(mp[i][k],mp[i][j]+mp[j][k]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		u--,v--;
		long long ans=INF;
		for(int i=0;i<l[u].size();i++){
			for(int j=0;j<l[v].size();j++){
				ans=min(ans,t[u][i]+t[v][j]+mp[l[u][i]][l[v][j]]);
			}
		}
		ans+=w[u]+w[v];
		cout<<ans<<'\n';
	}
	cout.flush();
	return 0;
}
