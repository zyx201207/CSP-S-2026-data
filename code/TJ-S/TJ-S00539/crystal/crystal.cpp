#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000],num[1000000],ans=0,m1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
    m1=m;
	for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		m=m1;
		for(int j=1;j<i;j++)
		{
		    if(m>0)
		    {
		    	if(a[i]-a[j]<m)
		    	{
		    		m=a[j]+m-a[i];
		    		a[j]=a[i];
				    
				}
			}
		    if(a[j]==a[j+1])
		    {
		    	num[i]++;
			}
			
	    }
	}
    for(int i=1;i<=n;i++)
    {
    	if(a[i]==a[i+1])
    	{
    		num[1]++;
		}
	}
	for(int i=1;i<=n;i++)
    {
    	ans=max(num[i],ans);
	}
    cout<<ans+1;
    return 0;
}	

