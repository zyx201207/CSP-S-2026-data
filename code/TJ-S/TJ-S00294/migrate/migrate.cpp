#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF=1e9;
const ll MAXN=2e6+99;
ll c,t,n,d;
ll pos[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
		}
		if(d>2){
			cout<<0<<endl;
			continue;
		}
		if(n>=4){
			cout<<n-4+1<<"\n";
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
} 

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3- 2 -1 3 6


*/
