#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],s;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d ",&a[i]);
		scanf("%c",&c[i]);
	}
	int k=1,d=n;
	while(k<d)
	{
		if(c[k]!=c[d])
		{
			s+=min(a[k],a[d]);
		}
		if(a[k]>a[d])
		{
			a[k]-=a[d];
			d--;
		}
		else if(a[k]<a[d])
		{
			a[d]-=a[k];
			k++;
		}
		else
		{
			d--;
			k++;
		}
	}
	cout<<s;
	return 0;
}
