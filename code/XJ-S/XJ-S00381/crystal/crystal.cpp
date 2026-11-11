#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[100001],sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	    	for(int j=1;j<=m;j++)
	    	{
	    		if(a[i]>=a[i-1])
	    		    a[i]++;
	            sum++;
		    }
	    
	}
	cout<<sum<<endl;
}
