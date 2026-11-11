#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int xx[500005];
int e[500505][500505],js=0;
int dis[500505];
int dfs(int wz,int zd){
	if(wz==zd)return dis[wz];
	for(int i=1;i<=m;i++){
		int ls=dis[wz]+e[wz][i];
		if(ls<dis[i]){
			dis[i]=ls;
			dfs(i,e[wz][i]);
		}
	}
	return dis[wz];
}
signed main(){
	//freopen("subway1.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>xx[i];
	for(int i=1;i<=n;i++){
		int ls;
		cin>>ls;
		for(int j=1;j<=ls;j++){
			int a,t;
			cin>>a>>t;
			e[a][++js]=t;
			e[js][a]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		for(int j=1;j<=m;j++)dis[j]=0;
		int ls=dfs(l,r);
		cout<<xx[l]+ls+xx[r]<<"\n";
		cout<<"ans=xx[l]("<<xx[l]<<")+dfs(l,r)("<<ls<<")+xx[r]("<<xx[r]<<")\n";
	}
	return 0;
}
