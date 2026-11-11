#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
	cin>>w[i];}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int zd,ti;cin>>zd>>ti;
		}
	}
	while(q--){	
		int x,y;cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	} 
}