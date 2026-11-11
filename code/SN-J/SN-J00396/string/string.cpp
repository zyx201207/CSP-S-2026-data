#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],c[200005],l[200005],r[200005];
long long a1[200005],c1[200005],l1[200005],r1[200005];
long long len,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>a[i]>>x;
		c[i]=x-'a';
		a1[n+1-i]=a[i];
		c1[n+1-i]=c[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+a[i]-1;
		len+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		l1[i]=r1[i-1]+1;
		r1[i]=l1[i]+a1[i]-1;
		//cout<<l1[i]<<" "<<r1[i]<<" "<<a1[i]<<" "<<c1[i]<<endl;
	}
	int d=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=d;j<=n;j++)
		{
			long long add=0;
			if(l[i]<=l1[j]&&r1[j]<=r[i])
			{
				if(c[i]!=c1[j])add=a1[j];
				d=j;
			}
			else if(l1[j]<=l[i]&&r[i]<=r1[j])
			{
				if(c[i]!=c1[j])add=a[i];
				d=j;
			}
			else if(l1[j]<=l[i]&&r1[j]<=r[i]&&(r1[j]>=l[i]))
			{
				if(c[i]!=c1[j])add=r1[j]-l[i]+1;
				d=j;
			}
			else if(l[i]<=l1[j]&&r[i]<=r1[j]&&(r[i]>=l1[j]))
			{
				if(c[i]!=c1[j])add=r[i]-l1[j]+1;
				d=j;
			}
			else if(l1[j]>r[i])
			{
				break;
			}
			ans+=add;
			
		}
	}
	ans/=2;
	cout<<ans;
	
	
	return 0;
 } 
