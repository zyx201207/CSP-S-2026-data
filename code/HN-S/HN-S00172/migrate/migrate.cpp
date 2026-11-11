#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[100005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[1]<0){
			cout<<(a[n]+a[1])/m<<"\n";
			continue;
		}
		cout<<(a[n]-1)/m<<"\n";
	}
	return 0;
}

