#include<bits/stdc++.h>
using namespace std;
const long long INF=5e17;
struct S{
	long long a,b;
};
vector<S> v[500005];
vector<S> g[505];
long long T,n,m,d,q,s[505][505],z[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	cin>>T>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>z[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			s[i][j]=INF;
		}
	}
	for(long long i=1,c,a,b;i<=n;i++){
		s[i][i]=0;
		cin>>c;
		while(c--){
			cin>>a>>b;
			g[i].push_back({a,b});
			v[a].push_back({i,b});
		}
	}
	for(long long i=1;i<=n;i++){
		for(auto j:g[i]){
			for(auto k:v[j.a]){
				s[i][k.a]=min(s[i][k.a],k.b+j.b);
			}
		}
	}
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	long long a,b,ans=INF;
	while(q--){
		cin>>a>>b;
		for(auto i:v[a]){
			for(auto j:v[b]){
				ans=min(ans,s[i.a][j.a]+i.b+j.b);
			} 
		}
		cout<<ans+z[a]+z[b]<<"\n";
	}
	return 0;
} 
/*
*/