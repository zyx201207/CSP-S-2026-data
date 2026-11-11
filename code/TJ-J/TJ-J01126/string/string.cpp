#include<bits/stdc++.h> 
using namespace std; 
int n,a[200005],f=1;
char c[200005];
long long ans=0;
int cnt=0;
int num=1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int m=(n+1)/2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		if(c[i]!=c[i+1])
		{
			f=0;
			num+=1;
		}
	}
	if(f==1)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
    {
	    cnt+=a[i];
    }
    if(num!=2)
    {
    	if(cnt%2==0)
        {
	        ans++;
        }
	}
    int x=m-1,y=m+1;
    for(int i=1;i<=n;i++)
    {
    	if(x==0&&y==n)
	    {
		    break;
	    }
        if(a[x]<a[y])	
        {
            ans+=a[x];
            x--;y++;
	   }
	   else if(a[x]==a[y])
	   {
		    ans+=a[x];
		    x--;y++;
	   }
	  else
	   {
		    ans+=a[y];
		    x--;y++;
	   }
	}
	if(num==2)
	{
		ans+=a[m];
	}
    cout<<ans;
	return 0;
}
