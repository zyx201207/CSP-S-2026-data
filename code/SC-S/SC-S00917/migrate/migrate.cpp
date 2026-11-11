#include<bits/stdc++.h>
using namespace std;
long long arr[2000001];
long long arr1[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int j=0;j<t;j++)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		if(n<=3)
		{
			cout<<0<<endl;
		}
		else
		{
		    for(int i=1;i<n;i++)
		    {
			    arr1[i]=arr[i]-arr[i-1];
		    }	
			long long k=d/arr1[1];
		    if(k>=n-1||k%2==1)
		    {
			    cout<<0<<endl;
		    }		
		    else
			{
				cout<<n-k-1<<endl;
			}
		}
	}
	return 0;
}