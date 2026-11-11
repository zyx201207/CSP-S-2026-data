#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;

ll a[N];
ll n,d;
ll k;
void solve1(){
	ll ans=0;
	for(ll l=1;l<=n;l++){
		for(ll r=l+1;r<=n;r++){
			ll cnt=0;
			if(abs(a[r]-a[l])<=d) continue;
			for(ll k=l+1;k<r;k++){
				if(abs(a[k]-a[l])<=d && abs(a[r]-a[k])<=d){
					cnt++;
//					cout<<l<<" "<<k<<" "<<r<<"\n";
				}
			}
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	if(d<2*k){
		cout<<"0\n";
		return ;
	}else if(d==2*k){
		cout<<n-3<<"\n";
	}else{
		cout<<(a[n]-a[1])/k<<"\n";
	}
	return ;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		k=0;
		for(int i=1;i<=n;i++) cin>>a[i],k=a[i]-a[i-1];
		if(n<=300){
			solve1();
			continue;
		}else{
			solve2();
			continue;
		} 
	} 


	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7 3
1 2 3 4 5 6 7

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989


*/ 


