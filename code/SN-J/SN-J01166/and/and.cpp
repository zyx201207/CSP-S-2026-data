#include<iostream>
using namespace std;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int b[n];
	for (int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int max=0;
	for (int i=1;i<=n;i++)
	{
		int a=(b[i-1] & b[i]);
		if (a>max)
		{
			max=a;
		}
	}
	cout<<max;
    return 0;	
}
