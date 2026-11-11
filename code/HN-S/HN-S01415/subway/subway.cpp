#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,z=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m],x[q],y[q],k[m];
	int a[n][m],t[n][m];
	int s[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][k[i]]>>t[i][k[i]];
		}
	}
	for(int r=0;r<q;r++)cin>>x[r]>>y[r];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==a[i+1][j]){
				s[z]=a[i][j];
				z++;
			}
		}
	}
	return 0;
}
