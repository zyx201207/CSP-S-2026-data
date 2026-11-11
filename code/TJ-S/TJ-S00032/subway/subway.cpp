#include<bits/stdc++.h>
using  namespace std;
int k[505],t[505][50005],a[505][50005],l[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector <int> w(m);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	 
	return 0;
} 
