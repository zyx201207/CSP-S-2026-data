#include <bits/stdc++.h>
using namespace std;
long long sum;
long long n,m;
long long a[500010];
long long pre[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		if(i*a[i]-pre[i]<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
} 
