#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,a[1000005];
int main()
{
	preopen("and.in","r",stdin);
	preopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	cout<<a[n];
	return 0;
}