#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[2000005],d,ans;
int c,t,n;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>a[i];
		if (d%2==1){
			cout<<0<<"\n";
			continue;
		}
		ans=n-4*d/2+1;
		cout<<ans<<"\n";
	}
	return 0;
}