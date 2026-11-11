#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10100],a[1000][1000],t[1000][1000],x[10010],y[10010],k[10100];
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
			cin>>a[i][k[i]]>>t[i][k[i]];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int ans=0;
		for(int j=1;j<=k[i];j++){
			if(a[x[i]][j]==y[i]) ans=w[x[i]]+a[x[i]][j]+a[y[i]][j]+w[y[i]]; 
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
