#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,T,n,d,a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(int t = 1;t<=T;t++){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[n];
		}
		cout<<t<<endl;
	}
	return 0;
}
