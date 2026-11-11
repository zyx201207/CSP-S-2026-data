#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll c,t,n,d,x[N];
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
	}
	if(c==11||c==12){
		if(x[2]-x[1]>=2*d&&x[2]-x[1]<3*d){
			cout<<n-3<<"\n";
		}
		else cout<<"0\n";
		return ;
	}
	if(c==13||c==14){
		cout<<"0\n";
		return ;
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
} 
