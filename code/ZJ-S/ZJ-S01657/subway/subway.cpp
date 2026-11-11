#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[514],w[514514];
long long a[514514];
bool cmp[514514];
struct _{
	vector<pair<int,int>>_;
}mp[514514];
//priority_queue<int,vector<int>,<int>>>pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int u;
			long long t;
			cin>>u>>t;
			mp[u]._.push_back({t,m+i});
			mp[m+i]._.push_back({t,u});
		}
	}
	for(int i=1;i<=q;++i){
		int st,ed;
		cin>>st>>ed;
		int v=st;
		for(int j=1;j<=n+m;++j)
		a[j]=5e15+114514,cmp[j]=false;
		a[st]=0;
		while(v!=ed){
			for(int j=0;j<mp[v]._.size();++j)
			a[mp[v]._[j].second]=min(a[v]+mp[v]._[j].first,a[mp[v]._[j].second]);
			long long mi=5e15;
			int mi2=-1;
			for(int j=1;j<=n+m;j++)
			if(mi>a[j]&&!cmp[j])
			mi=a[j],mi2=j;
			cmp[mi2]=true;
			v=mi2;
		}
		cout<<a[ed]+w[st]+w[ed]<<endl;
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/