#include<bits/stdc++.h>
using namespace std;
int sum,s,e,c,n,m,d,p,t[10000][10000],z[10000][10000],w[500005],a[10000],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=2*a[i];j++) cin>>z[i][j]>>t[i][j];
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		sum+=w[x]+w[y];
		for(int j=1;j<=a[i];j++){
			for(int q=1;q<=a[i+1];q++){
				if(z[2][j]==z[1][q]){
					sum+=t[2][j]+t[1][q];
					for(int k=1;k<=q;k++) sum+=t[1][q];
					for(int k=j;k<=z[3][j]-z[2][j];k++) sum+=t[2][k];
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
