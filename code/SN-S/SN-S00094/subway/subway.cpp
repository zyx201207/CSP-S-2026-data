#include<bits/stdc++.h>

using namespace std;
struct o_i{
	int vv,ww;
};
int c,n,m,d,q;
int w[1000000];
int v[1000000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c>>n>>m>>d>>q;
	fill(v,v+m,INT_MAX);
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<n;i++){
		int g;
		cin >> g;
		for(int j=0;j<g;j++){
			int w,ee;
			cin >> w>>ee;
			v[w]=min(v[w],ee);
		}
	}
	while(q--){
		int l,r;
		cin >> l>>r;
		cout << w[l]+v[l]+v[r]+w[r]<<endl;
	}
	return 0; 
}
