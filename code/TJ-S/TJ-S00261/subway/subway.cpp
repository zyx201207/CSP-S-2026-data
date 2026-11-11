#include<bits/stdc++.h>
using namespace std;
struct A{
	int station;
	int time;
}b[500010][500010];
int vis[500010][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	int a[500010];
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int f=1;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k!=2) f=0;
		for(int j=1;j<=k;j++){
			cin>>b[i][j].station;
			cin>>b[i][j].time;
			vis[i][j]=1;
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		int c=0;
		c+=a[x];
		c+=a[y];
		if(f){
			int mi=INT_MAX;
			for(int i=1;i<=m;i++){
				if(vis[x][i]==1) mi=min(mi,vis[x][i]);	
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
