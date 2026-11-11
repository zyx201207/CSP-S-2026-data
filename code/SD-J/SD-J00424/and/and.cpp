#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long x=a[n-1];
	for(int i=n-2;i>=n-m;i--) x=x&a[i];
	cout<<x;
	return 0;
}
