#include <iostream>
using namespace std;
int n,m,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a2[200005][200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
    for(int i=1;i<=m;i++)
    {
    	for(int j=1;j<=m;j++)
        {
        	a2[i][j]=a[i] and a[j];
    	}
	}
	int sum=0;
    for(int i=1;i<=m;i++)
    {
    	for(int j=1;j<=m;j++)
        {
        	if(a2[i][j]>sum)
        	{
        		sum=a2[i][j];
			}
    	}
	}
	cout<<sum;
    return 0;
}
