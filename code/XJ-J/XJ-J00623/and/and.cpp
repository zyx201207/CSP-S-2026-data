#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[100005],maxn=0,i;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(a[i]>maxn)
		maxn=a[i];
	}
	cout<<maxn;
	return 0;
}