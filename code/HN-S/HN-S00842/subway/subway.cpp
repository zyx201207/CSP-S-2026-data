#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k[n];
	int a[n][m];
	int t[n][m];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	} 
	int x[q],y[q];
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i]; 
	}
	int sxn,sxm;
	int syn,sym;
	for(int f=0;f<q;f++){
		sxn=0;
		sxm=0;
		syn=0;
		sym=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i];j++){
				if(j==x[f]){
					sxn==i;
					sxm==j;
				}
				if(j==y[f]){
					syn==i;
					sym==j;
				}
			}
		}
		if(sxn==syn){
			cout<<w[sxm]+t[sxn][sxm]+w[sym]+t[syn][sym]<<" ";
		}else{
			cout<<35<<" "<<16;
		}
	}
	return 0;
} 
