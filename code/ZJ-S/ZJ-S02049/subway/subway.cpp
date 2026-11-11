#include<bits/stdc++.h>
using namespace std;
const long long g=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k,a,h[500010][21],f[500010];
long long ans,w[500010],t[500010][21],dis[501][501];
void floyed(){
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			dis[i][j]=g;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			f[a]++;
			cin>>t[a][f[a]];
			h[a][f[a]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=f[i];j++){
			for(int o=j+1;o<=f[i];o++){
				dis[h[i][j]][h[i][o]]=min(dis[h[i][j]][h[i][o]],t[i][j]+t[i][o]);
				dis[h[i][o]][h[i][j]]=min(dis[h[i][o]][h[i][j]],t[i][j]+t[i][o]);
			}
		}
	}
	floyed();
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=g;
		for(int i=1;i<=f[x];i++){
			for(int j=1;j<=f[y];j++){
				ans=min(ans,dis[h[x][i]][h[y][j]]+t[x][i]+t[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

