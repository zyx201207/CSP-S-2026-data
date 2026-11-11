#include <bits/stdc++.h>
using namespace std;
int c,n,m,ddd,q,w[700005],k,a,t,x,y;
long long ans,d[700505];
struct asd{
	int v;
	long long w;
};
vector<asd>as[700505];
void dij(int s,int t){
	memset(d,127,sizeof(d));
	set<pair<long long,int>>f;
	d[s]=0;
	f.insert({d[s],s});
	while(!f.empty()){
		auto ip=f.begin();
		int fi=ip->first,se=ip->second;
		f.erase(ip);
		if(se==t)
			return;
		for(auto y:as[se]){
			if(d[se]+y.w<d[y.v]){
				f.erase({d[y.v],y.v});
				d[y.v]=d[se]+y.w;
				f.insert({d[y.v],y.v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>ddd>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			as[a].push_back({i+m+1,t});
			as[i+m+1].push_back({a,t});
		}
	}
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y];
		dij(x,y);
		cout<<ans+d[y]<<endl;
	}
	return 0;
}