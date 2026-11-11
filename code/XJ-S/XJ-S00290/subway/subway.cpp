#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int t[500010];
int l[500][500010];
int k[500];
int q[100010][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>l[i][j];
		} 
	}
	for(int i=1;i<=p;i++){
		cin>>q[i][1]>>q[i][2];
	}
	return 0;
}
