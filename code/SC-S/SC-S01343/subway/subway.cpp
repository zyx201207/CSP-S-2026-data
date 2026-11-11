#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010];
bool p[500010],p2[510];
map<long long,long long> a[510];
vector<long long>b[510];
long long f(long long x,long long y){
	p[x]=1;
	long long mn=1e9;
	for(long long i=1;i<=n;i++){
		if(p2[i]==0){
			p2[i]=1;
			if(a[i].count(x)){
				if(a[i].count(y)){
					mn=min(mn,a[i][y]+a[i][x]); 
				}else{
					for(long long j=0;j<b[i].size();j++){
						if(p[b[i][j]]==0)mn=min(f(b[i][j],y)+a[i][x]+a[i][b[i][j]],mn);
					}
				}
			}
			p2[i]=0;
		}
	}
	p[x]=0;
	return mn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			long long x,t;
			cin>>x>>t;
			a[i][x]=t;
			b[i].push_back(x);
		}
	}
	for(long long i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+f(x,y)<<"\n";
	}
	return 0;
}
