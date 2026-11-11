#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,maxn,a[2500000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	 cin>>a[i];
	for(i=1;i<=n;i++)
	 if(a[i]&a[i+1]>maxn)
	  maxn=a[i]&a[i+1];
	cout<<maxn;
	
	return 0;
}
