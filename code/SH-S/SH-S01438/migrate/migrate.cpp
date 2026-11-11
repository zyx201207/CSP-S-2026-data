#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll a[2000005],m;
void solveA(){
	ll d=a[2]-a[1];
	ll b=m/d;
	if(b<=1){
		cout<<0<<'\n';
		return; 
	}
	if(2*b-1>n){
		cout<<0<<'\n';
		return;
	}
	cout<<n-(2*b-1)<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++) a[i]=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
//		if(11<=c && c<=12) solveA();
//		else solveA();
		solveA();
	}
	return 0;
}
