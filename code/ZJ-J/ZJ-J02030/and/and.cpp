#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200009];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long max=-1;
	long long all;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>max) max=a[i];
		if(i==1) all=a[i];
		else all=all & a[i];
	}
	if(m==2) {
		long long mx=0,o;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				o=a[i]&a[j];
				if(o>mx) mx=o;
			}
		}
		printf("%lld",mx);
		return 0;
	} else if(m==1) cout<<max;
	else if(m==n) cout<<all;
	else cout<<4;
	return 0;
}

