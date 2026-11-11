#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
    	
    	
    	int n,d;
    	cin>>n>>d;
    	for(int j=0;j<n;j++)
    	{
    		cin>>a[j];
		}
		int ans=0;
    	for(int j=0;j+3<n;j++)
    	{
    		if(a[j+1]-a[j]<=d&&a[j+2]-a[j+1]<=d&&a[j+3]-a[j+2]<=d&&a[j+2]-a[j]<=d&&a[j+3]-a[j+1]<=d)
    		{
    			ans+=1;
			}
		}
		cout<<ans<<"\n";
    	
    	
    	
    	
	}




	return 0;
}
