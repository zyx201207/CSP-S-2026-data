#include<bits/stdc++.h>
using namespace std;
long long a[200005],sum,l=1,r,m1;
int n;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	while(l<r)
	{
		m1=min(a[l],a[r]);
		if(c[l]!=c[r]) sum+=m1;
		a[l]-=m1,a[r]-=m1;
		if(a[l]==0) l++;
		else if(a[r]==0) r--;
	}
	cout<<sum;
	return 0;
}
