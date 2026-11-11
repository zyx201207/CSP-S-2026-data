#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool tp(long long a){
	while(a>1){
		if(a%2!=0){
			return 0;
		}
		a/=2;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=2147483647;
	while(tp(a[n])&&n>m){
		n--;
	}
	for(int i=n;i>=n-m+1;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

