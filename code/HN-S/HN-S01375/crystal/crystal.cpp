#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[500005],ans=0,ans1=1;
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
    	for(int j=i;j>=1;j--)
    	{
     		if(a[i]-a[j]<=m)
    		{ 
    			m-=(a[i]-a[j]);
    			ans1++;
    		}
        }
    	ans=max(ans,ans1);
    	ans1=1;
	}
	cout<<ans;
	fclose(stdin);	
	fclose(stdout);
	return 0;
}
