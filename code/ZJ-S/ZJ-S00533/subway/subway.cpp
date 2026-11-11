#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,mn=0x3f3f3f,w[5500],k[550],a[550][5500],x[10086],y[10086];
int mp[5500][30],mp1[5500][30],t[550][5500],p[5500][5500];
//c：编号，n：地铁线数，m地铁站数，d站点经过最多线数
//q计划数，p站间最小值 ，mp经过的站点,a
int v[500];
void dfs(int x,int y,int s){
	if(x==y) mn=min(mn,s);
	for(int i=1;i<=mp[x][0];i++){
		if(v[mp[x][i]]==1) continue;
		v[mp[x][i]]=1;
		for(int j=1;j<=k[mp[x][i]];j++){
			int f=1;
			for(int l=1;l<=mp[a[mp[x][i]][j]][0];l++){
				if(v[mp[a[mp[x][i]][j]][l]]) f=0;
			}
			if(f==0){
				dfs(a[mp[x][i]][j],y,s+t[mp[x][i]][j]+t[mp[x][i]][mp1[x][i]]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	memset(p,0x3f3f3f,sizeof(p));
	for(int i=0;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			mp[a[i][j]][0]++;
			mp[a[i][j]][mp[a[i][j]][0]]=i;
			mp1[a[i][j]][mp[a[i][j]][0]]=j;
		}
	}
	for(int i=1;i<=q;i++){
		mn=0x3f3f3f;
		memset(v,0,sizeof(v));
		dfs(x[i],y[i],w[x[i]]+w[y[i]]);
		cout<<mn<<endl;
	}
}
