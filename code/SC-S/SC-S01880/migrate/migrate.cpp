#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,d,a[N],ans,m=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			m=max(m,a[i]);
		}
		ans=n*d/log(m);
		cout<<ans<<'\n';
	}
	
	return 0;
}
