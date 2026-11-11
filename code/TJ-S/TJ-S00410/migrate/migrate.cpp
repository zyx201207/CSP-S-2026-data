#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll n,d;
ll a[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			a[2]=a[1]+d;
		}
	}
	ll p=a[2]-a[1];
	p=d/p;
	if(p<=1){
		cout<<"0\n";
	}else{
		p=p*2-1;
		cout<<max(0ll,n-p)<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

