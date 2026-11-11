#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(nullptr);
	long long n;
	cin>>n;
	long long a[n+1],he=0;
	char c[n+1];
	for(long long i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long ans=0,pi=0,pj=0;
	for(long long i=0,j=n-1;i<j&&i<n&&j>=0;)
	{
		long long oi=i,oj=j;
		if(c[i]!=c[j])
		{
			ans+=min(a[oi],a[oj]);
		}
		if(a[i]>a[j])
		{
			a[i]-=a[j];
			j--;
		}
		else if(a[j]>a[i])
		{
			a[j]-=a[i];
			i++;
		}
		else
		{
			i++,j--;
		}
		pi+=max(a[i],a[j]);
		pj+=max(a[i],a[j]); 
	}
	cout<<ans;
	return 0;
}

