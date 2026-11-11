#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,xx,yy,ans,w[500005],k[505],f[505][505];
vector<pair<long long,long long> > s[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			s[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<s[i].size();j++){
			for(int l=j+1;l<s[i].size();l++){
				x=s[i][j].first,y=s[i][j].second;
				xx=s[i][l].first,yy=s[i][l].second;
				f[x][xx]=min(f[x][xx],y+yy);
				f[xx][x]=min(f[xx][x],y+yy);
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[j][i]=f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				ans=min(ans,f[s[x][i].first][s[y][j].first]+s[x][i].second+s[y][j].second);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	
	return 0;
}
/* I'm the god !!! And I'm not the god of qu either !!! */

/* er deng yao xiang xin ping ce ji , ta hui dai ling ru zhi chang shu zou xiang ac O(m*d*d+n*n*n)*/