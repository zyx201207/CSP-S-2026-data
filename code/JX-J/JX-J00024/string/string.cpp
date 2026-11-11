#include<bits/stdc++.h>
using namespace std;
long long n,a[100000005],m=0,b=0;
char s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i]>>s[i];
		m+=a[i];
	}
	if(n==1)
    {
		 cout<<"0";
		 return 0;
    }
	if(m%2==0)
	{
        for(long long i=1;i<=n/2;i++)
	    {
		    for(long long j=n;j>=n/2+1;j--)
		    {
			    if(s[i]!=s[j])
			    {
				    s[j]=s[i];
				    b+=a[i];
			     }
	        }
	     }
     }
     if(m%2==1)
	{
        for(long long i=1;i<=n/2;i++)
	    {
		    for(long long j=n;j>=n/2+2;j--)
		    {
			    if(s[i]!=s[j])
			    {
				    s[j]=s[i];
				    b+=a[i];
			     }
	        }
	     }
     }
     cout<<b;
   return 0;
}
