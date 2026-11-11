#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500010;
ll n,m;
ll a[N];
bool check1(){
	for(ll i=1;i<=n;i++){
		if(a[i]!=i)return 0;
	}
	return 1;
}
void solve1(){
	ll sum=0;
	ll cnt=1;
	for(ll i=1;i<=n;i++){
		if(sum+i>m){
			cout<<cnt<<endl;
			return;
		}
		else{
			sum+=i;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return;
}
bool check2(){
	ll ch=a[2]-a[1];
	for(ll i=2;i<=n-1;i++){
		if(a[i+1]-a[i]!=ch)return 0;

	}
	return 1;
}
void solve2(){
	ll ch=a[2]-a[1];
	ll sum=0;
	ll cnt=1;
	for(ll i=1;i<=n;i++){
		if(sum+ch*i>m){
			cout<<cnt<<endl;
			return;
		}
		else{
			sum+=i;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return;
}
ll prech[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	if(check1()){
		solve1();
		return 0;
	}
	if(check2()){
		solve2();
		return 0;
	}
	prech[1]=0;
	prech[2]=a[2]-a[1];
	for(ll i=3;i<=n;i++){
		prech[i]=prech[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if(prech[i]>m){
			cout<<cnt<<endl;
			return 0;
		}
		else{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
