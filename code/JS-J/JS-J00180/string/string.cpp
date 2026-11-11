#include <iostream>
using namespace std;
int n;
int  a[100005];
char c[100005];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int i=0,j=n-1;
	int d=0;
	while (i<n)
	{
		if(d<0&&c[i]!=c[j+1])
		{
			ans-=d;
		}
		d+=a[i];
		if(d<0&&c[i]!=c[j+1])
		{
			ans+=d;
		}
		while(d>0)
		{
			d-=a[j];
			if(c[i]!=c[j])
			{
				if(d>0)
				ans+=a[j];
				else
				ans+=a[j]+d;
			}
			j--;
		}
		i++;
	}
	cout<<ans/2;
	return 0;
}

