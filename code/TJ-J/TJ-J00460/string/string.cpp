#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int a[200005];
char c[200005];
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j)
	{
		if(a[i]>a[j])
		{
			if(c[i]!=c[j]) ans+=a[i]-a[j];
			a[i]-=a[j];
			j--;
		}
		else if(a[i]<a[j])
		{
			if(c[i]!=c[j]) ans+=a[j]-a[i];
			a[j]-=a[i];
			i++;
		}
		else 
		{
			if(c[i]!=c[j]) ans+=a[j];
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
