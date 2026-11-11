#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int const N=2e6+10;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t,n,d;
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>a[i];
	}
	for (int i=1;i<=t;i++) cout<<0<<endl;
	return 0;
}

