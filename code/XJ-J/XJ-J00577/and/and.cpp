#include<bits/stdc++.h>
using namespace std;
long long int ans,n,m,a[200005]; 
int main()
{
	long long int i,j;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);  
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n,greater<long long int>());
	ans=a[1];
	for(i=1;i<=m;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
