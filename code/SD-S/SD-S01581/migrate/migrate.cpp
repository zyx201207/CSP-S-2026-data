#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[3]-a[1]>d||n<4) cout<<0<<'\n';
		else cout<<n-(((a[2]-a[1])/d)*2+1)+1<<'\n';
	}

	return 0;
}

