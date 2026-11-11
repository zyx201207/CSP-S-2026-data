#include<bits/stdc++.h> 
#define ll long long
using namespace std;
ll a[10000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	ll sum=0;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l = a[1];
	ll r = n;
	ll mid = (l+r)/2;
	if(a[mid+1] == a[mid]){
		mid+=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			cout<<2<<endl;
			return 0;
		}
	}
	cout<<mid<<endl;
	return 0;
}
