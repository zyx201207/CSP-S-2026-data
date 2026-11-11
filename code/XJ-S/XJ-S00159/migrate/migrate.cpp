#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+5;
int c,t,n,d,x[N]; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","W",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		int c=x[2]-x[1],ans=0;
		int di=d/c;
		ans=n-(2*di)+(n-3);
		//cout<<2*di<<' '<<d<<' '<<c<<' '<<ans<<' '<<n-(2*di)+(n-3)<<'/n';
		cout<<ans<<'\n';
	}
	return 0;
} 
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
/*
0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6
 */

