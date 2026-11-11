#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int ans;
	for(int i = 1;i <= n;i++)
	{
    	if(a[i] <= m && a[i+1] > m || (i == n && a[i] <= m))
    	{
   			if(a[1] >= 0)
    		{
    			cout<<a[i] - a[1];
    			return 0;
       		}
       		
       		cout<<a[1] + a[i];
       		return 0;
       	}
		
   	}
    return 0;
}
