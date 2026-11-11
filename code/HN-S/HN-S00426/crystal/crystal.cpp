#include<bits/stdc++.h>
using namespace std;
/*
这个神人代码又发疯了 
Oct31==Dec25?
*/
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=0; i<n; i++)cerr<<a[i]<<" ";cerr<<endl;
	for(long long i=0; i<n; i++)cin>>a[i];
	sort(a, a+n);
	long long h[n];
	h[0]=0;
	for(long long i=1; i<n; i++) {
		h[i]=(a[i]-a[i-1])*i+h[i-1];
	}
	for(long long i=0; i<n; i++)cerr<<h[i]<<" ";cerr<<endl;
	long long l=0,r=n,mid=0,p=0;
	for(; r>=l;) {
		mid=(l+r)/2;
		if(h[mid]>m) {
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	p=mid;
	cout<<p;
	return 0;
}
