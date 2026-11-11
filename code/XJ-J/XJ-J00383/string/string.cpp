#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,a[200005],t=0;
string c[200005],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(i<=j)
	{
		if(a[i]>a[j])
		{
			if(c[i]!=c[j])
			{
				t+=a[j];
			}
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j])
		{
			if(c[i]!=c[j])
			{
				t+=a[i];
			}
			a[j]-=a[i];
			i++;
		}
		else
		{
			if(c[i]!=c[j])
			{
				t+=a[i];
			}
			i++,j--;
		}
	}
	cout<<t;
	return 0;
}
