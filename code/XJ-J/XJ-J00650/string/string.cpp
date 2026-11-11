#include<bits/stdc++.h>
using namespace std;
long long int n,a[210000],ans;
char c[210000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]>a[r])
		{
			a[l]-=a[r];
			r--;
		}
		else if(a[r]>a[l])
		{
			a[r]-=a[l];
			l++;
		}
		else
		{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}