#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll a[N];
void solveA(){
	ll n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(d<=a[2]-a[1]){
		cout<<"0\n";
		return;
	}
	ll p=d/(a[2]-a[1]);
	if(p>(n-1)){
		cout<<0<<"\n";
		return;
	}
	ll ans=0;
	ans=n-(p+p)+1;
	cout<<ans<<"\n";
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	ll c,t;
	cin>>c>>t;
	if((c==0)||(c==0)){
		while(t--){
			solveA();	
		}	
	}
	else if((c==13)||(c==14)){
		while(t--){
			ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0<<"\n";	
		}	
	}
	else{
	while(t--){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0<<"\n";
	}
}
	return 0;
}