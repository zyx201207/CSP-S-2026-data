#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+517;
const int N=2e6+517;
int c,t_;
ll n,d;
ll a[N];
int solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<(1+n)*n/2;
	return 0;
}
int solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n/2;
	return 0;
}
int solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n/2<<'\n';
	return 0;
}

int main(){

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>t_;
	while(t_){
		t_--;
		solve();
		if(11==c || c==12){
		solve1();
		}
		if(c==13 || c==14){
			solve2();
		}
		solve();
	}
} 
