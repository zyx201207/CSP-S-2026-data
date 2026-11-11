#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans = a[n];
	for(int i=1;i<m;i++){
		ans = a[n-i] % ans;
	}
	cout<<ans;
	return 0;
}