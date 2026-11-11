#include<bits/stdc++.h>
using namespace std;
long long n,i,j,a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	if(n==1)
	cout<<0;
	return 0;
}