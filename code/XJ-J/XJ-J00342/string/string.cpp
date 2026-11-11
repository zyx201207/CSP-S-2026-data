#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,c,d;
	int l,a[200005];
	long long sum=0;
	cin>>l;
	
	for(int i=0;i<l;i++)
	{
		cin>>a[i];
		sum+=a[i];
		cin>>s[i];
		c=s;
	}
	if(sum%2==0){
	
	   for(int i=0;i<sum;i++)
	   {
		   c+=s[i];
		   if(c+c==s)
		   {
		   	    cout<<0;
		   	    break;
		   }
		   else{
		   	    cout<<sum/2;
		   	    break;
		   }
	   }
    }
    else
    {
    	for(int i=0;i<sum;i++)
    	{
    		sort(c.begin(),c.end(),cmp);
    		if(c==s)
    		{
    			cout<<0;
    			break;
			}
    		else
    		{
    			cout<<sum/2;
    			break;
			}
    		
		}
	}
	return 0;
}