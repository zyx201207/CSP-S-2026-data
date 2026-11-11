#include<bits/stdc++.h>
#define AC return 0
using namespace std;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;vector<int>a(n+1);
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<n/2+1<<'\n';
	}AC;
}