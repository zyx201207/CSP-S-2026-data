#include<bits/stdc++.h>
using namespace std;
struct aa{
	int k;
	int a[k]={},t[k]={};
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int z,n,m,d,q;
	cin>>z>>n>>m>>d>>q;
	aa aa[n];
	int w[m]={};
	for(int i=0;i,m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>aa[i].k;
		for(int j=0;j<aa[i].k;j++){
			cin>>aa[i].a[j]>>aa[i].k[j];
		}
	}
	int b[m][m]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<aa[i].k;j++){
			for(int k=0;k<aa[i].k;k++){
				b[aa[i].a[j]][aa[i].a[k]]=aa[i].t[j];
			}
		}
	}
	for(int k=0;k<m;k++){
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<b[x][y]+w[x+w[y]];
	}
	return 0;
} 
