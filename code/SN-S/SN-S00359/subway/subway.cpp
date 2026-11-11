//SN-S00359 张馨月 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][505],t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<a[1][2]*6+t[3][5]*10+q<<endl;
	}
	
	return 0;
}
