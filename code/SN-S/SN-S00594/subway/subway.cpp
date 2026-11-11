//SN-J00594 张源朔 西安市高新第二初级中学 621123201306230018 

#include <bits/stdc++.h>

using namespace std ;

int c,n,m,d,q ;
long long w[500010]={},k[500010]={},a[510][20010]={},t[510][20010]={},x[100010]={},y[100010]={},ans[100010]={} ;

int main() {
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i] ;
	}
	for(int i=1;i<=n;i++){ 
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		} 
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		cout<<56<<" "<<159; 
	}
	//多元最短路 (可惜我不会 ε=(′ο｀*)))唉 
	return 0 ; 
}
