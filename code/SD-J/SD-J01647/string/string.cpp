#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long a[N],cnt=0;
char c[N];
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
		if(c[l]!=c[r])
		{
			if(a[l]>a[r])
			{
				cnt+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				cnt+=a[l];
				l++,r--;
			}
			else
			{
				cnt+=a[l];
				a[r]-=a[l];
				l++;
			}
			
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]==a[r])
			{
				l++,r--;
			}
			else
			{
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
