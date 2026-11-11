#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define unsigned long long
ll rd(){
	ll sm=0,fe=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fe=-1;
	for(;isdigit(c);c=getchar()) sm=sm*10+c-'0';
	return sm*fe;
}
int m,n,w[500007],pppp,c[500001],q,d,k[501],minn[501];
vector<int>bl[500007];
vector<int>v[500007];
ll f[507][507];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	pppp=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++) w[i]=rd();
	memset(minn,0x3f,sizeof(minn));
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		k[i]=rd();
		for(int j=1;j<=k[i];j++){
			int u=rd(),ww=rd();
			bl[u].push_back(i);
			c[u]++;
			v[u].push_back(ww);
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=c[i];j++){
			for(int k=1;k<=c[i];k++){
				int x=bl[i][j-1],y=bl[i][k-1];
				f[x][y]=min(f[x][y],0ll+v[i][j-1]+v[i][k-1]);
				f[y][x]=min(f[x][y],0ll+v[i][j-1]+v[i][k-1]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<' ';
		}cout<<'\n';
	}*/
	while(q--){
		int stt=rd(),ed=rd();
		ll ans=LLONG_MAX;
		for(int i=1;i<=c[stt];i++){
			for(int j=1;j<=c[ed];j++){
				ans=min(ans,f[bl[stt][i-1]][bl[ed][j-1]]+v[stt][i-1]+v[ed][j-1]);
			}
		}
		cout<<ans+w[stt]+w[ed]<<'\n';
	}
	return 0;
}
