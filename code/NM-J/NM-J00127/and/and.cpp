#include <iostream>
using namespace std;
int a[1000][1000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cout<<a[i][0];
		int sum=0;
		while(a[i][0]>=1)
		{
			a[i][sum]=a[i][0]%2;
			a[i][0]=a[i][0]/2;
			sum++;
		}
	}
	cout<<a[n][0];
}
