#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	vector<int> w(m);
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		for(int j=1;j<=2*q;j++){
			int x; cin>>x;
		}
	}
	while(q--){
		int x,y; cin>>x>>y;
		cout<<w[x]+w[y];
	}
	return 0;
}