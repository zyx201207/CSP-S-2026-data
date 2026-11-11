#include <iostream>
using namespace std;
int b(int a, int s)
{
	return a and s;
}
int main()
{
	int n, m, a[n], sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		    if(sum<b(a[i],a[j]))
		    {
		    	sum=b(a[i],a[j]);
		    }
	    }
	}
	cout<<sum;
	return 0;
}