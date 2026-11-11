#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int c,t;
int a[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		int n,d;
		cin>>n>>d;
		int x,maxx;
		int f = 0;; 
		for(int i = 1; i<= n; i++) {
			cin>>a[i];
			if(i!=1&&x!=a[i]-a[i-1]){
				f = 1;
			}
			x=  a[i]-a[i-1];
			if(x>d) {
				maxx = i-1;
			}
		}
		int asd=  0;
		int cnt = 2;
		while(d>=cnt*x) {
			asd+=n-cnt-1; 
			cnt++;
		}
		if(f){
			cout<<0<<"\n";
		}else{
			cout<<asd<<"\n";	
		}
		
	}
	return 0;
}
