#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll a[500005],m;
ll c[500005];
ll q[500005];
int n;//45+eps  pts
//kaolv tongyi yigequjiannei de shu
// er fen da an?
bool check(int l,int x){//qu a[l]~a[x-1 yu a[x] de cha zhihe
	ll ans=0;
	ans+=(q[x]-q[l-1]);
	ans-=(a[n]-a[x])*1ll*(x-l+1);
	/*
	for(int i=l;i<=x;i++){
		ans+=(a[x]-a[i]);
	}*/
	if(ans<=m)return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
	sort(a+1,a+n+1);
for(int i=1;i<n;i++){
	c[i]=a[n]-a[i];
	q[i]=q[i-1]+c[i];
}
	int ma=INT_MIN;
for(int i=n-1;i>=1;i--){
	int l=i+1,r=n;
	//erfen diyige bumanzu tiaojian de j
	while(l<r){
		int mid=l+(r-l)/2;
		if(check(i,mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
//	cout<<l<<" "<<i<<endl;
	ma=max(ma,l-i);
}
	cout<<ma;
	return 0;
}// CSP-S 2026 RP++

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
