#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5*1e5+10;
ll n,m,r,l,a[N],ans=1,O=0;
bool f(ll x){
	ll num=0,sum=0;
	for(int i=0;i+x<=n;i++){
		num=0,sum=0;
		for(int j=i;j<x;j++){
			num+=a[j];}
		num/=x;
		for(int j=i;j<x;j++){
			sum+=abs(num-a[j]);}
		if(m>=sum)return 1;}return 0;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];if(i>1)if(a[i]-a[i-1]!=a[i-1]-a[i-2])O=1;}
	if(O==0){
		ll c=a[1]-a[0],i=1;
		while(1){
			if(m>=c*i){ans++;m-=c*i;}
			if(m>=c*i){ans++;m-=c*i;}
			else{cout<<ans;return 0;}
			i++;}}
	sort(a,a+n);
	r=1,l=n;
	do{
		ll mid=(r+l)>>1;
		if(f(mid)){ans=mid;r=mid+1;}
		else l=mid;
	}while(r<l);
	if(r==l&&f(r))ans=max(ans,r);
	cout<<ans;
	return 0;}
