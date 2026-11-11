#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int p,n,m,d,q,r,w[N],a[N][N],z[N][N],c[N],b[N],sum=0;
	cin>>p>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>r;
		for(int j=1;j<=r;j++){
			cin>>a[i][j]>>z[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>b[i];
		int cc=c[i],bb=b[i],ic,ib;
		sum+=w[cc]+w[bb];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=r;j++){
			if(a[i][j]==cc){
				ic=i;
				sum+=z[i][j];
			} 
			if(a[i][j]==bb){
				ib=i;
				sum+=z[i][j];
			}
	}
	}
		for(int i=1;i<=r;i++){
			for(int j=1;j<=r;j++){
				if(a[ic][i]==a[ib][i]){
					sum+=z[ic][i];
				}
			}
		}
	
	}
	
	return 0;
}
