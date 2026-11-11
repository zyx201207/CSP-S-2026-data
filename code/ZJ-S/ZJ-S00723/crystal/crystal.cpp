#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
ll a[N],s[N],m;
int n;
bool check(int x){
	ll y=1e18+10;
	for(int i=x;i<=n;i++){
		ll z=a[i]*x-(s[i]-s[i-x]);
		y=min(z,y);
	}
	return (y<=m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
