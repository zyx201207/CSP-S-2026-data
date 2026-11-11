#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,r;
const int maxn=2*1e5+5;
long long a[maxn];
char aa;
long long c[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
    	cin>>a[i]>>aa;
    	c[i]=int(aa);
	}
	l=1,r=n;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(a[l]<a[r])
			{
				a[r]-=a[l];l++;
			}
			else if(a[l]>a[r])
			{
				a[l]-=a[r];r--;
			}
			else if(a[l]==a[r])
			{
				l++;r--;
			}
		}
		else
		{
			if(a[l]<a[r])
			{
				a[r]-=a[l];ans+=a[l];l++;
			}
			else if(a[l]>a[r])
			{
				a[l]-=a[r];ans+=a[r];r--;
			}
			else if(a[l]==a[r])
			{
				ans+=a[l];l++;r--;
			}
	    }
	}
	cout<<ans;
		fclose(stdin);
	fclose(stdout);
    return 0;
}
