#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll c,t;
ll x[N],cha[N],ans[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	bool check=false;
	for(ll i=1;i<=t;i++){
		ll n,d;
		cin>>n>>d;
		for(ll j=1;j<=n;j++){
			cin>>x[j];
			cha[j]=x[j+1]-x[j];
			if(cha[j]==cha[j+1]==cha[j+2]){
				ans[i]=x[j]/abs(d-n);
			}
			if(cha[n]-cha[1]<=d) check=true;
		}
		if(check==true) ans[i]==n-1;
	}
	for(ll i=t;i>=1;i--){
		cout<<ans[i]<<"\n";
	}
	return 0;
}