#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500001],first_tr[501],x,y;
vector<pair<pair<long long,long long>,long long>>e[500001];
vector<pair<long long,pair<long long,long long>>>g[500001];
vector<pair<long long,long long>>line[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=0;j<k;j++){
			long long a,t;
			cin>>a>>t;
			line[i].push_back({a,t});
		}
		g[line[i][0].first].push_back({i,{-1,line[i][1].first}});
		for(int j=1;j<k-1;j++){
			g[line[i][j].first].push_back({i,{line[i][j-1].first,line[i][j+1].first}});
		}
		g[line[i][k-1].first].push_back({i,{line[i][k-2].first,-1}});
	}
	for(int i=1;i<=n;i++){
		long long pre_tr=-1;
		for(int j=0;j<line[i].size();j++){
			if(g[line[i][j].first].size()>=2){
				if(pre_tr!=-1)e[line[i][j].first].push_back({{pre_tr,line[i][j].second+line[i][pre_tr].second},i});
				else first_tr[i]=line[i][j].first;
				pre_tr=j;
			}
		}
		long long suf_tr=-1;
		for(int j=line[i].size()-1;j>=0;j--){
			if(g[line[i][j].first].size()>=2){
				if(suf_tr!=-1)e[line[i][j].first].push_back({{suf_tr,line[i][j].second+line[i][suf_tr].second},i});
				suf_tr=j;
			}
		}
	}
	while(q--){
		cin>>x>>y;
	}
	return 0;
}
