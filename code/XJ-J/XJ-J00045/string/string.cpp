#include<bits/stdc++.h>
using namespace std;
char c[200005];int n,a[200005];
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int r=1,l=n;
	while(r<l)
	{
		if(c[r]==c[l])
		{
			if(a[r]>a[l])
			{
				a[r]-=a[l];
				l--;
			}
			else if(a[r]==a[l])
			{
				r++;
				l--;
			}
			else
			{
				a[l]-=a[r];
				r++;
			}
		}
		else
		{
			if(a[r]>a[l])
			{
				cnt=cnt+a[l];
				a[r]-=a[l];
				l--;
			}
			else if(a[r]==a[l])
			{
				cnt+=a[l];
				r++;
				l--;
			}
			else
			{
				cnt=cnt+a[r];
				a[l]-=a[r];
				r++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
