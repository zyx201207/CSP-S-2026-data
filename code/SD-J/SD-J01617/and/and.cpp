#include<bits/stdc++.h>//32
#define ll long long
using namespace std;
const int N=2*1e5+10;
ll ans,n,m,a[N];
ll ad(ll x,ll y){
	ll num=0,log=1;
	while(1){
		if(!x&&!y)return num;
		if((x%2)&(y%2))num+=log*1;
		x/=2,y/=2;log*=2;}}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];}
	if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=ad(ans,a[i]);}
		cout<<ans;
		return 0;
	}if(m==1){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=max(ans,a[i]);}
		cout<<ans;return 0;}
	if(m==2){
		ans=ad(a[0],a[1]);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,ad(a[i],a[j]));
		}}cout<<ans;return 0;}
	if(m==n-1){
		ll x=LLONG_MIN;
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=(ans&a[i]);}
		for(int i=0;i<n;i++){
			x=max(x,ans&a[i]);}
		cout<<x;return 0;}
	sort(a,a+n);
	cout<<a[n-m];
	return 0;}
