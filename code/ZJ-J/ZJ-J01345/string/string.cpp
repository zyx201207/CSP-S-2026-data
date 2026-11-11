#include<bits/stdc++.h>
using namespace std;
long long n,a[2000000],l,r,cs;
char c[2000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l<r)
	{
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])
			{
				cs+=a[r];
				a[l]-=a[r];
				r--;
			}
			else a[l]-=a[r],r--;
		}
		else
		{
			if(c[l]!=c[r])
			{
				cs+=a[l];
				a[r]-=a[l];
				l++;
			}
			else a[r]-=a[l],l++;
		}
	}
	cout<<cs;
	

}
