#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out",",w",stdout);
    int n,m,max=0;
    cin>>n>>m;
    int a[n];
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i+1])
	    {
		    max=a[i];
	    }
	} 
	cout<<max;
	return 0;
} 
