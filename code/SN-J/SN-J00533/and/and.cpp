#include <bits/stdc++.h>
using namespace std;
int cc[20005];
int main()
{
	freopen("and.in";"r";stdin);
    freopen("and.out";"w";stdout);
    string a;
    long long n,m,max=-10000;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(long long i=1;i<=n-m+1;i++)
    {
    	int n=a[i];
    	for(int u=1;u<=m-1;u++)
    	{
    		n^=a[i+u];
		}
		if(n>max)
		{
			max=n;
		}
	}
	cout<<max;
	return 0;
}
