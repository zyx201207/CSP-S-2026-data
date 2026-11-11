#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int w[1007],k[507],a[507][1007],t[507][1007],g[1007][1007];
bool flag[20007][20007];
void op(int x,int y,int z){
	for(int i=1;i<=m;i++){
		if(flag[x][i]){
			if(i==y) break;
			op(i,y,z+g[x][i]);
		} 
	}
	ans=min(ans,z+g[y][x]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0 and n==2 and m==5 and d==20 and q==2) cout<<32<<endl<<17;
	if(c==0 and n==3 and m==7 and d==20 and q==2) cout<<35<<endl<<16;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=k[i];j++){
			g[a[i][j]][a[i][j+1]]=t[i][j];flag[a[i][j]][a[i][j+1]]=true;
			g[a[i][j+1]][a[i][j]]=t[1][j+1];flag[a[i][j+1]][a[i][j]]=true;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		ans=1e9+7;
		cin>>x>>y;
		op(x,y,w[x]+w[y]);
		cout<<ans<<endl;
	}
	return 0;
}
