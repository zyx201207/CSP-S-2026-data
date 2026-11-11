#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long sum;
string c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%s",&a[i],&c[i]);
	for(int i=1,j=n;i<j;i++,j--)
		if(c[i]!=c[j])
		{
			sum+=max(a[i],a[j]);
			if(a[i]>a[j])
				a[i+1]+=a[i]-a[j];
			else
				a[j-1]+=a[j]-a[i];
		}	
	cout<<sum;	
	return 0;
}
