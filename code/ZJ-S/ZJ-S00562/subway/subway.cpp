#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500009],k,a[509][50009],t[509][50009],f[50009][5009],ans,v[500009];
void dg(int xx,int yy,int sum){
	if(xx==yy){
		ans=min(ans,sum);
		return;
	}
	if(f[xx][yy]!=1e7){
		ans=min(ans,sum+f[xx][yy]-w[xx]-w[yy]);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==1||f[i][xx]==1e7)continue;
		v[i]=0;
		dg(i,yy,sum+f[i][xx]-w[i]-w[xx]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=1e7;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int tt;
			cin>>a[i][j]>>tt;
			t[i][a[i][j]]=tt;
			for(int l=1;l<=j-1;l++){
				f[a[i][l]][a[i][j]]=min(f[a[i][l]][a[i][j]],w[a[i][l]]+w[a[i][j]]+t[i][a[i][l]]+t[i][a[i][j]]);
				f[a[i][j]][a[i][l]]=f[a[i][l]][a[i][j]];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(f[x][y]!=1e7){
			cout<<f[x][y]<<endl;
			continue;
		}
		ans=INT_MAX;
		v[x]=1;
		dg(x,y,w[x]+w[y]);
		v[x]=0;
		f[x][y]=ans;
		cout<<ans<<endl;
	}
}
