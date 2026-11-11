#include<bits/stdc++.h>
using namespace std;
int n,m,ans,x,y,z;
int a[500005];
int c;
int main()
{
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	 x=a[i]-a[i-1];
    	 m-=x;
		 if(m>=0)
		 {
		 	ans++;
		 } 
	}
	cout<<ans; 
	return 0;
}





















/*#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005];
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	 int a1=0,a2=0;
	 int c=0;
	 sort(a+1,a+n+1);
	 a[0]=a[a1];
	 for(int i=1;i<=n;i++)
	 {
	 	c+=(a1-a2)*(a[i]-a[i-1]);
	    while(c>m)
	    {
	    	
	 	  ans=max(ans,i-a1+1);
	 	  	a1++;
	    }
	    cout<<ans;
	 }
	return 0;
}*/
