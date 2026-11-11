#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int c,T;
int n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		int k = a[n]-a[n-1];
		if(k>=d){
			cout<<0<<endl;
			continue;
		}
		int kk = 3;
		while(d>=3*k){
			k*=2;
			kk*=2;
		}
		cout<<n-kk<<endl;
	}
}