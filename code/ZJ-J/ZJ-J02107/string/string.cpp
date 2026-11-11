#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int n;
int cnt=0;
long long sum=0;
int a[maxn+5];
long long na[maxn+5];
char c[maxn+5],nc[maxn+5];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1])
		{
			na[++cnt]=a[i];
			nc[cnt]=c[i];
		}
		else na[cnt]+=a[i];
		sum+=a[i];
	}
	int l=1,r=cnt;
	long long ans=0;
	while(l<r)
	{
		if(nc[l]==nc[r])
		{
			if(na[l]==na[r]) l++,r--;
			else if(na[l]>na[r])
			{
				na[l]-=na[r];
				r--;
			}
			else
			{
				na[r]-=na[l];
				l++;
			}
		}
		else
		{
			if(na[l]==na[r])
			{
				ans+=na[l];
				l++,r--;
			}
			else if(na[l]>na[r])
			{
				na[l]-=na[r];
				ans+=na[r];
				r--;
			}
			else
			{
				na[r]-=na[l];
				ans+=na[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
