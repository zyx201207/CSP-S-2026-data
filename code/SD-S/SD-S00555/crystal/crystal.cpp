#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define to0(x) memset(x,0,sizeof x)
#define to_1(x) memset(x,-1,sizeof x)
#define toinf(x) memset(x,0x3f,sizeof x)
#define pb push_back
#define Debug cout<<"DEBUG\n";
#define Deon(x) cout<<"DEBUG:"<<x<<'\n';
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

const int N = 5e5+5;
ll sm[N],a[N],n,m; 

bool chk(ll md) {
	bool f=0;
	for(int i=1;i+md-1<=n;i++) {
		if(1ll*(md)*a[i+md-1]-(sm[i+md-1]-sm[i-1])<=m) {
			f=1; 
		}
	}
	return f;
}

int main() {
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
	
//	cout<<chk(315275)<<'\n';
 	ll l=1,r=n,as=1;
 	while(l<=r) {
 		ll md=(l+r)>>1;
// 		cout<<l<<" "<<r<<" "<<md<<'\n'; 
 		if(chk(md)) as=max(as,md),l=md+1;
 		else r=md-1;
	}
	
	cout<<as;

	return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

3:3845
4:315275
*/

