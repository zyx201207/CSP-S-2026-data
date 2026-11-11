#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],i,sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<long long>());
	for(i=1;i<=k;i++)
	if(sum==0)sum=a[i];
	else sum=sum&a[i];
	cout<<sum;
	return 0;
}
