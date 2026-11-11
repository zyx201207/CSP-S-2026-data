#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long a[N],n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<a[m];
	return 0;
}