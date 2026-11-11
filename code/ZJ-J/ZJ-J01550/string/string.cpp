#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long s;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=1,r;
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			s+=min(a[l],a[r]);
		}
		if(a[l]<a[r])
		{
			a[r]-=a[l];
			l++;
		}
		else
		{
			if(a[l]==a[r])
			{
				l++;
				r--;
			}
			else
			{
				a[l]-=a[r];
				r--;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}