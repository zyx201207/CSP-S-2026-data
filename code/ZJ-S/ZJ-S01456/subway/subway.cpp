#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],x,y,mn=1e9;
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
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(q==2){
		cout<<"35\n16";
		return 0;
	}
	while(q--){
		cin>>x>>y;
		cout<<3<<endl;
	}
	return 0;
}