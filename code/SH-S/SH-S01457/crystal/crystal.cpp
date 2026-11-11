#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005]; 
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
	int ans=0,cnt=0;
	long long  l=1,r=n;
    for(int i=1;i<=n;i++)
    {
    	long long mid=l+(r-1)/2;
        for(int j=mid;j>=1;j--)
        {
        	while(ans<=m)
			{
        		ans+=a[mid]-a[i];	
			}
			a[i]=a[mid];
		}
		if(a[i]=a[mid])
		{
		    cnt++;
		}
		
	}
	cout<<cnt<<endl;
	return 0;
} 
