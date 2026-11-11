#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[500010],a[510][500010],t[510][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			if(j%2) cin>>a[i][j/2+1];
			else cin>>t[i][j/2];
		} 
	}
}	

