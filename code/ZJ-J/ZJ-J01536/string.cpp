#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
	freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x=0,ne=0;
	cin>>n;
	for(int i=1,y;i<=n;i++)
	{
		char z;
		cin>>y>>z;
		if(z==b[x])
		{
		    a[x]+=y;
		    e++;
		}
		else
		{
			x++;
			a[x]=y;
			b[x]=z;
		}
		ne+=y;
	}
	long long l=1,r=x,ans=0,re=0,le=0;
	while(re+le<ne)
	{
		if(b[l]==b[r])
		{
			if(a[l]>a[r])
			{
				r--;
				a[l]-=a[r];
				re+=a[r];
				le+=a[r];
			}
			else if(a[l]<a[r])
			{
				l++;
				a[r]-=a[l];
				re+=a[l];
				le+=a[l];
			}
			else 
			{
				r--;
				l++;
				re+=a[r];
				le+=a[r];
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				r--;
				a[l]-=a[r];
				ans+=a[r];
				re+=a[r];
				le+=a[r];
			}
			else if(a[l]<a[r])
			{
				l++;
				a[r]-=a[l];
				ans+=a[l];
				re+=a[l];
				le+=a[l];
			}
			else 
			{
				r--;
				l++;
				ans+=a[r];
				re+=a[r];
				le+=a[r];
			}
		}
		if(l==r)break;
	}
	cout<<ans;	
}