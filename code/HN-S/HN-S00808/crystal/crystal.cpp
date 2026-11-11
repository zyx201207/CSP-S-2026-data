#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],num=1,c=1,ans=0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
    } 
   	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		if(a[i]==a[i+1]){
			num++;
		}
		if(a[i]+1==a[i+1]){
			ans+=a[i];
			c++;
		}
	}
	if(n==num){
		cout<<n;
		return 0;
	}
	if(c==n){
		if(m>=ans){
			cout<<n;
			return 0;
		}
	}
	return 0;
}

