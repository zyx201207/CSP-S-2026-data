#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[500005],xr,yr,f[505][505],dr=1e18+7;
long long as,ts;
struct one{
	long long a,x;
}ui,uj;
vector<one> di[500005];
vector<long long> a[505],t[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18+7;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&as,&ts);
			a[i].push_back(as);
			t[i].push_back(ts);
			di[as].push_back((one){i,ts});
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)di[i].size();j++){
			for(int o=j+1;o<(int)di[i].size();o++){
				ui=di[i][j];
				uj=di[i][o];
				f[uj.a][ui.a]=f[ui.a][uj.a]=min(f[ui.a][uj.a],ui.x+uj.x);
			}
		}
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][o]+f[o][j]);
			}
		}
	}
	while(q--){
		cin>>xr>>yr;
		if(xr==yr){
			cout<<0<<'\n';
			continue;
		}
		dr=1e18+7;
		for(int j=0;j<(int)di[xr].size();j++){
			for(int o=0;o<(int)di[yr].size();o++){
				ui=di[xr][j];
				uj=di[yr][o];
				dr=min(dr,f[ui.a][uj.a]+ui.x+uj.x+w[xr]+w[yr]);				
			}
		}
		cout<<dr<<'\n';
	}
	return 0;
}
