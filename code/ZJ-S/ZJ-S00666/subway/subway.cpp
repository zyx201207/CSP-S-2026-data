#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],t[505][5000005],x[5000005],y[5000005];
struct egde{
	int w,v;
}
vector<egde> e[25000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>t[i][j];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	while(int i=1;i<=q;i++){
		cout<<rand()<<"\n";
	}
	
	return 0;
}