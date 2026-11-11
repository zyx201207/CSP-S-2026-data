#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a[10000000],c,s;
	long long n,i,b[1000000],ans=0;
	cin>>n;
	for(i=1;i<=n;i++);
	{
		cin>>a[i]>>b[i];
		for(i=1;i<=b[i];i++);
	{
		s=a[i];	
	}	
	}
	
	if(s=a[n])
	cout<<0<<endl;
	else
	{
		while(s!=a[i])
		{
			c=a[i]-s;
			s=s-c;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
