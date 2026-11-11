#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	if(m==1){cout<<a[1];return 0;}
	cout<<a[m];
	/*
	for(int i = 2;i<=m;i++){
		if(a[i]==a[1]){
			
		}
		else{
			a[1]&=a[i];
		}
	}
	cout<<a[1];
	*/
	return 0;
}
