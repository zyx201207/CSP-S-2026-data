#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000];
int main()
{
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<a[m+1];
	return 0;
} 
