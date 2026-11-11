#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	int x[20009];
	int m[20009];
	int s;
	char a;
	for (int i=0;i<n;i++)
	{
	    
	    cin>>s>>a;
	    x[i]=a;
	    m[i]=s;
    }
	long long ans=0;
	int l=0;
	int r=n-1;
	while (l<=r)
	    {
	    	if (x[l]!=x[r])
	    	{
		    	if (m[l]>m[r])
		    	{
		    		ans+=m[r];
		    		m[l]=m[l]-m[r];
		    		r--;
		    	}
		    	else if (m[l]<m[r])
		    	{
		    		ans+=m[l];
		    		m[r]=m[r]-m[l];
		    		l++;
		    	}
		    	else
		    	{
		    		ans+=m[l];
		    		l++;
		    		r--;
				}
	    	}
	    	else if (x[l]==x[r])
	    	{
		    	if (m[l]>m[r])
		    	{
		    		m[l]=m[l]-m[r];
		    		r--;
		    	}
		    	else if (m[l]<m[r])
		    	{
		    		m[r]=m[r]-m[l];
		    		l++;
		    	}
	    		else
	    		{
	    			l++;
	    			r--;
	    		}
	    	}
	    }
 	cout<<ans;
}
