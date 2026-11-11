#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int c,t,a[N];
bool is(int x){
	for(int i=3;i<=x;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return 0;
	}
	return 1;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){	
		int d,n;
		cin>>n>>d; 
		for(int i=1;i<=n;i++) cin>>a[i];
		if(is(n)){
			int o=d/(a[2]-a[1]);
			if(n>=o*2) cout<<n-o*2+1<<'\n';
		}
	}
	return 0; 
}
//Oct31==Dec25?
//1 2 3 4 5 6 7
//1->2,2->4
//1->3,3->4