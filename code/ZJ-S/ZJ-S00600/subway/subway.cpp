#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],t[500][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a1,t1,a;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>t[i][a];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int mi=INT_MAX;
		for(int i=1;i<=n;i++){
			if(t[i][x]!=0 && t[i][y]!=0)
				mi=min(t[i][x]+t[i][y]+w[x]+w[y],mi);
		}
		for(int i=1;i<=n;i++){
			for(int k=i;k<=n;k++){
				for(int j=1;j<=m;j++){
					if(j==x || j==y)	continue;
					if(t[i][x]!=0 && t[i][j]!=0 && t[k][j]!=0 && t[k][y]!=0){
						mi=min(t[i][x]+t[i][j]+t[k][j]+t[k][y]+w[x]+w[y],mi);
					}
				}
			}
		}
		cout<<mi<<endl;
	}
	return 0;
}
