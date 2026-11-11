#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	ll maxn = 0;
	cin>>n>>m;
	for(ll i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);//ÅÅÐò
	for(ll i = n;i>=m;i--){
		maxn = a[i]&a[i-1];
	}
	cout<<maxn<<endl;
	return 0;
}
