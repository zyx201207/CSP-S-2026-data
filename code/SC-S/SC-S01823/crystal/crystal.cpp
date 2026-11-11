#include <bits/stdc++.h>
using namespace std;
const int N=500005;
#define ll long long 
ll n,m,a[N],d,x;
ll bs(ll x){
	if(x<0){
		return -x;
	}else{
		return x;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	d=bs(a[2]-a[1]);
	x=m/d;
	for(int i=sqrt(x*2);i<=x;i++){
		if(i*(i+1)/2>x){
			cout<<i;
			return 0;
		}
	}
	return 0;
}