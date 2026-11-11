#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
int a[maxn];
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll sum=0;
	ll l=1,r=n;
	while(l<r){
		ll k,x;
		if(c[l]!=c[r]){
			k=1;
		}else{
			k=0;
		}
		if(a[l]>=a[r]){
			x=a[r];
			a[r]=0;
			a[l]-=x;
			r--;
		}else{
			x=a[l];
			a[l]=0;
			a[r]-=x;
			l++;
		}
		sum+=k*x;
	}
	cout<<sum;
	return 0;
}