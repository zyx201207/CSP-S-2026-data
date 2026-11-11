#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,a[N],m,l,r,ma,b[N];
bool check(ll x){
	for(int i=1;i<=n-x+1;i++){
		ll y=0;
		y=x*a[x+i-1]-(b[x+i-1]-b[i-1]);
		if(y<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	l=1,r=n;
	while(l<r){
		ll mid=l+r>>1;
		if(check(mid)){
			ma=max(ma,mid);
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ma;
	return 0;
}  
