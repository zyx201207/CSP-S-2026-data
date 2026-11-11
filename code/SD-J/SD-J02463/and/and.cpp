#include <bits/stdc++.h>
using namespace std;
int n,m,sum=-1;
int a[10000]; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		sum=max(a[j]^a[i+1],sum);
		}
	}
	cout<<sum;


	fclose(stdin);
	fclose(stdout);
	return 0;
}
