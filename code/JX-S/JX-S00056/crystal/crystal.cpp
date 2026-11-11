#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
long long m;
long long a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		int l=1;long long k=m;
		if(ans>=i)
		{
			cout<<ans;
			return 0;
		}
		
         for(int j=i-1;j>=1;j--)
         {
			 
			 if(k-a[i]+a[j]>=0)
			 {
				 l++;
				 k=k-a[i]+a[j];
			 }
			 else
			 {
				 break;
			 }
		 }
		 ans=max(ans,l);
	 }
	 cout<<ans;
    return 0;
}
