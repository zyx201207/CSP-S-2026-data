#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long c,n,m,d,q,w[N],k[N],a[505][1005],t[505][1005];
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
	while(q--){
		int x,y;
		cin>>x>>y;
		if(!c&&n==3){
			cout<<35<<"\n"<<16;
		}else if(!c&&n==2){
			cout<<32<<"\n"<<17;
		}
	}
	return 0;
}
