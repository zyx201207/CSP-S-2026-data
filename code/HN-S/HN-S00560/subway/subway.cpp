#include<bits/stdc++.h>
using namespace std;
long long c1,n,m,d,q,k,a[500005],x,y,b[500005],c3[500005][505];
vector<pair<long long,long long>> c[505];
vector<long long> c2[500005];
long long aaa(long long o,long long p){
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> e;
	for(int i=1;i<=m;i++){
		b[m]=LLONG_MAX;
	}
	b[o]=0;
	e.push({0,o});
	while(e.size()){
		auto f=e.top();
		e.pop();
		if(b[f.second]!=f.first){
			continue;
		}
		for(auto g:c2[f.second]){
			for(auto h:c[g]){
				if(h.first!=f.second){
					if(b[h.first]>b[f.second]+c3[f.second][g]+h.second){
						b[h.first]=b[f.second]+c3[f.second][g]+h.second;
					}
				}
			}
		}
	}
	return b[p];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=i;j<=k;j++){
			cin>>x>>y;
			c[i].push_back({x,y});
			c2[x].push_back(j);
			c3[x][i]=y;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<aaa(x,y)+a[x]+a[y];
	}
}
