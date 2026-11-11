#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500+10;
const int M=5e5+10;
int c,n,m,d,q;
ll w[M];
int k[N];
vector<pair<int,ll>> hc[M];
ll xl[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			xl[i][j]=LLONG_MAX;
		}
	}
	int len;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		ll x,y;
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			hc[x].push_back({i,y});
			len=hc[x].size();
			if(len>=2){
				auto yy=hc[x][len-1];
				for(int ii=0;ii<len-1;ii++){
					auto xx=hc[x][ii];
					xl[xx.first][yy.first]=min(xl[xx.first][yy.first],(ll)xx.second+(ll)yy.second);
					xl[yy.first][xx.first]=min(xl[yy.first][xx.first],(ll)xx.second+(ll)yy.second);
				}
			}
		}
	}
	int st,en;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(xl[i][j]==LLONG_MAX) continue;
			for(int k=1;k<=n;k++){
				if(j==k||xl[i][k]==LLONG_MAX) continue;
				xl[j][k]=min(xl[j][k],xl[i][j]+xl[i][k]);
				xl[k][j]=xl[j][k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		xl[i][i]=0;
	}
	while(q--){
		cin>>st>>en;
		ll minn=LLONG_MAX;
		for(auto i:hc[st]){
			for(auto j:hc[en]){
				minn=min(xl[i.first][j.first]+i.second+j.second,minn);
			}
		}
		cout<<minn+w[st]+w[en]<<"\n";
	}
	return 0;
}
