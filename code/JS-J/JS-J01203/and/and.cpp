#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=k;i++) a[1]&=a[k];
	cout<<a[1];
	return 0;
}
