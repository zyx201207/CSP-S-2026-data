#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100],s=0,b=0,c=0,d=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s+=a[i];
		for(int j=1;j<=n;j++)
		{
			if(a[j+1]==s[i])
			{
				s=0;
			}
		}
    }  
    for(int i=1;i<=n;i++)
    {
    	if(s[i]==a[0])
    	{
    		b++;
		}
		if(s[i]==a[1])
    	{
    		c++;
		}
		if(s[i]==a[2])
    	{
    		d++;
		}
	}
	cout<<b<<" "<<c<<" "<<d;
	return 0;
}
