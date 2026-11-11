#include<bits/stdc++.h>
#define int long
using namespace std;
const int N=2*1e6+9;
int n,d,c,t;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int int k=1;k<=t;k++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		cout<<(n-2*d)+1;
	}
	return 0;
}
