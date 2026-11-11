#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<long long>w(m+1);
	for(long long i=1;i<=m;i++)cin>>w[i];
	vector<vector<pair<long long,long long>>>st(m+1);
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=0;j<k;j++){
			long long a,t;
			cin>>a>>t;
			st[a].push_back({i,t});
		}
	}
	vector<vector<long long>>t(n+1,vector<long long>(n+1,(1LL<<60)));
	for(long long i=1;i<=n;i++)t[i][i]=0;
	for(long long v=1;v<=m;v++){
		auto&vec=st[v];
		for(long long a=0;a<vec.size();a++){
			for(long long b=a+1;b<vec.size();b++)if(vec[a].second+vec[b].second<t[vec[a].first][vec[b].first])t[vec[a].first][vec[b].first]=t[vec[b].first][vec[a].first]=vec[a].second+vec[b].second;
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1; i<=n;i++){
			if(t[i][k]==(1LL<<60))continue;
			for(long long j=1;j<=n;j++){
				if(t[k][j]==(1LL<<60))continue;
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		long long ans=(1LL<<60);
		for(auto[li,ti]:st[x])for(auto[lj,tj]:st[y])ans=min(ans,w[x]+ti+t[li][lj]+tj+w[y]);
		cout<<ans;
	}
}//我是tang*
