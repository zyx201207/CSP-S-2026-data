#include <iostream>
using namespace std;
int n;
long long a[100000005];
char c[100000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
    	cin >> a[i] >> c[i];
	}
	char a2[100000005],a3[100000005];
	int sum=0;
    for(int i=1;i<=n;i++)
    {
    	for(int j=a[i];j<=n;j++)
        {
        	a2[j]=c[sum];
        	sum++;
    	}
	}
	for(int i=1;i<=n;i++)
    {
    	for(int j=n;j>=n/2;j--)
    	{
    		a3[i]=a2[i];
    		a3[j]=a2[i];
    	}
	}
	int num=0;
	for(int i=1;i<=n;i++)
	{
	    if(a2[i]!=a3[i])
	    {
	    	num++;
		}
	}
	cout<<num;
    return 0;
}
