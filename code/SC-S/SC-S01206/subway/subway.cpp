#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q1;
int w[500005],a[10005][10005],t[10005][10005],k[500005];
int b[10005][10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=1;q<=k[i];q++){
				for(int p=1;p<=k[j];p++){
					if(a[i][q]==a[j][p]) b[i][j]=a[i][q];
				}
			}
		}
	}
	while(q1--){
		int x,y,xi,xj,yi,yj;
		cin>>x>>y;
		int s=w[x]+w[y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x) xi=i,xj=j;
				if(a[i][j]==y) yi=i,yj=j;
			}
		}
		if(xi==yi){
			for(int i=min(xj,yj);i<=max(xj,yj);i++) s+=t[xi][i];
		}
		else{
			s+=t[xi][xj];
			s+=t[yi][yj];
		}
		cout<<s<<'\n';
	}
}