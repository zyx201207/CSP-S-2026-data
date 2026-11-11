#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=n;i>=n-m+2;i--){
		sum = sum & a[i-1];
	}
	cout<<sum;
	return 0;
}
