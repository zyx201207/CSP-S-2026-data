#include <bits/stdc++.h>
using namespace std;
long long n,m,cut=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int long long s[n],d[n],f=1;
	int long long a[n+1],b[m+1],ans;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s[a[i]]++;
		if(s[a[i]]>=2)
		{
			d[f]=i;
			f++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=n-m-1;i--)
	{
		b[cut]=a[i];
		cut++;
	}
	ans=b[1];
	for(int i=2;i<=cut;i++)
	{
		ans=ans&&b[i];
	}
	cout<<max(ans,a[d[f-2]]);
	return 0;
} 
