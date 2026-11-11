#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[100005],i,j,maxn;
int main()
{	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	if(m==1)
	{
		cout<<a[1];
	}
	if(m==2)
	{
	    maxn=a[1]&a[2];
		cout<<maxn;
	}
     return 0;
}