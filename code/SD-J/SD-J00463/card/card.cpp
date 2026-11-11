#include <iostream>
#include <cstdio>
using namespace std;
int a[500010];
int ans[300010];
int z[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	int e;
	e=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			e++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<i+e<<" ";
	}
    return 0;
}
