#include <bits/stdc++.h>
using namespace std;
const int M=2e4,N=500;
long long c,n,m,d,q;
long long w[M+5],k[N+5],dis[M+N+5];
vector<pair<long long,long long> >g[N+M+5];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			long long a,t;
			cin>>a>>t;
			g[n+a].push_back(make_pair(i,t));
			g[i].push_back(make_pair(n+a,t)); 
		}
	}
	set<pair<long long,long long> >s;
	map<pair<long long,long long>,long long>mp;
	for(int st=1;st<=n;st++){
		for (int i=1;i<=n+m;i++){
			dis[i]=(1LL<<60);
			s.insert(make_pair(dis[i],i));
		}
		s.erase(make_pair(dis[st],st));
		dis[st]=0;
		s.insert(make_pair(dis[st],st));
		while (!s.empty()){
			long long x=s.begin()->second;
			s.erase(make_pair(dis[x],x));
			for (int i=0;i<g[x].size();i++){
				long long ch=g[x][i].first,zh=g[x][i].second;
				if (dis[x]+zh<dis[ch]){
					s.erase(make_pair(dis[ch],ch));
					dis[ch]=dis[x]+zh;
					s.insert(make_pair(dis[ch],ch));
				}
			}
		}
		for (int i=1;i<=n+m;i++){
			mp[make_pair(st,i)]=dis[i];
		}
		s.clear();
	}
	while (q--){
		long long st,fh;
		cin>>st>>fh;
		long long ans=(1LL<<60);
		for (int i=0;i<g[n+st].size();i++){
			ans=min(ans,mp[make_pair(g[n+st][i].first,n+fh)]+g[n+st][i].second);
		}
		cout<<ans+w[st]+w[fh]<<endl;
	}
	return 0;
}

