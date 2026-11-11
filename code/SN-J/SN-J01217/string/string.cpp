#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
    long long n,l[200000],k=0;
    string a[20000],s[20000];
	string b1[8888],b2[8888];
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>l[i]>>a[i];
        while(l[i]>0)
    	{
    		s[k]=a[i];
    		k++;
    		l[i]--;
		}
	}
	long long c=0;
	if(k%2==0)
	{
	   for(int i=0;i<k/2;i++)
    	    b1[i]=s[i];
    }
    else
    {
	   for(int i=0;i<=k/2;i++)
    	    b1[i]=s[i];
    }
    int p=0;
    for(int i=k;i>k/2;i--)
    {
    	b2[p]=s[i];
    	p++;
	}
    for(int i=0;i<p;i++)
        if(b1[i]!=b2[i])
        	c++;
	cout<<c;
	return 0;
}
