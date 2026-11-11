#include<bits/stdc++.h>
using namespace std; 
int c,n,m,d,q,r[5][500001],rr[5][500001],num[500001],w[500001],k[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			r[++num[a]][a]=i;
			rr[++num[a]][a]=t;
		}
	} 
	for(int i=1;i<=q;i++){
		int ans=0x3f3f3f3f;
		int x,y;
		cin>>x>>y;
		if(c==20||c==21){//10·Ö 
			if(num[x]==1&&num[y]==1&&r[1][x]==r[1][y]){
				cout<<w[x]+w[y]+rr[1][x]+rr[1][y]<<'\n';
				continue;
			}
			if(num[x]==2&&num[y]==1&&r[1][x]==r[1][y]){
				cout<<w[x]+w[y]+rr[1][x]+rr[1][y]<<'\n';
				continue;
			}		
			if(num[x]==2&&num[y]==1&&r[2][x]==r[1][y]){
				cout<<w[x]+w[y]+rr[2][x]+rr[1][y]<<'\n';
				continue;
			}
			if(num[x]==1&&num[y]==2&&r[1][x]==r[1][y]){
				cout<<w[x]+w[y]+rr[1][x]+rr[1][y]<<'\n';
				continue;
			}
			if(num[x]==1&&num[y]==2&&r[1][x]==r[2][y]){
				cout<<w[x]+w[y]+rr[1][x]+rr[2][y]<<'\n';
				continue;
			}
			if(num[x]==2&&num[y]==2){
				cout<<w[x]+w[y]+min(rr[1][x]+rr[1][y],rr[2][x]+rr[2][y])<<'\n';
				continue;
			}
			for(int j=1;j<=m;j++){
				if(num[j]==2){
					ans=min(ans,rr[r[1][x]][j]+rr[r[1][y]][j]);
				}
			}
			cout<<ans+w[x]+w[y]+rr[1][x]+rr[1][y]<<'\n';
		}
	}
	return 0;
}
