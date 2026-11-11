#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005],max1=-1,maxx=-1,sw,ans;
bool bmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	max1=max(max1,a[i]);
	}
    sort(a+1,a+n+1,bmp);
    if(m==1) 
       {
       	cout<<max1;
       	return 0;
	   }
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		   for(int j=2;j<=n;j++)
		     if(i!=j)
		       {
		  	     int m=(a[i]&a[j]);
		  	     maxx=max(maxx,m);
		       }
	    cout<<maxx;
	    return 0;
	}
	if(m==n)
	  {
	  	 ans=a[1]&a[2];
	     for(int i=3;i<=n;i++)
	       ans=ans&a[i];
	     cout<<ans;
	  }
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
