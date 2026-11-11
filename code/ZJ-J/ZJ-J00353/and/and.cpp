#include<bits/stdc++.h>
using namespace std;
long long n,i,m,k;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	k=a[n];
	for(i=2;i<=m;i++){
		k=k&a[n-i];
	}
	cout<<k;
	return 0;
}
