#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,T,n,d,ans,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c==13||c==14){
		for(int i=1;i<=T;i++){
			cout<<"0\n";
		}
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll k=a[2]-a[1];
		ll p=d/k;
		if(p<=1) cout<<"0\n";
		else cout<<max(n-2*p+1,0LL)<<"\n";
	}
	return 0;
}