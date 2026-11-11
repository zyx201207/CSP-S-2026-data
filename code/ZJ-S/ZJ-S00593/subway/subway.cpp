#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int c,n,m,d,q;
int g[905][905];
int w[200005];
int k[200005];
int v[200005]; 
int sss=300;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0) ;
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m+600;i++){
		for(int j=1;j<=m+600;j++){
			g[i][j]=1e9;
			if(i==j)g[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int a,b;
		cin>>a>>b;
		if(v[a]==1){
			g[a][a+300+300]=b;
			g[a+300+300][a]=b;
			a+=300;
//			cout<<"mjmjmjmj";
		}else{
			v[a]=1;
			g[a][a+300]=b;
			g[a+300][a]=b;
		}
		
		int c,d;
		for(int j=2;j<=k[i];j++){

			cin>>c>>d;
			if(v[c]==0){
				v[c]=1;
				g[c][c+300]=d;
				g[c+300][c]=d;
				g[a+300][c+300]=0;
				g[c+300][a+300]=0;
//				cout<<a+300<<':'<<c+300<<endl;
			}else{
				g[c][c+300+300]=d;
				g[c+300+300][c]=d;
				g[a+300][c+300+300]=0;
				g[c+300+300][a+300]=0;
				c+=300;
//				cout<<a+300+sss<<':'<<c+300+sss<<endl;
			}
				
				a=c,b=d;
				
		}
	}
//	 for(int i=1;i<=900;i++){
//		for(int j=1;j<=900;j++){
//			if(g[i][j]!=1e9&&i!=j)cout<<i<<' '<<j<<' '<<g[i][j]<<endl;
//		}
//	}
	for(int k=1;k<=m+600;k++){
		for(int i=1;i<=m+600;i++){
			for(int j=1;j<=m+600;j++){
				if(g[i][k]+g[k][j]<g[i][j]){
					g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
	
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<w[a]+g[a][b]+w[b]<<endl;
	}
	return 0;
}
/*
17:37 24p
i am sad
ccf rp++ rp-- 
luogu User jfyjfy

*/
