#include <iostream>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m,mj=0,maxth,frem;
	cin >> n >> m;
	int a[n],b[n*n];
	int kbl[n][n];
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
	for(int i=0;i<n;i++)
	{
		for (int j = 0;j<n;j++)
		{

			mj++;
			int ks =a[i]- a[j];
			if (ks < 0)
			{
				ks=ks*-1;
			}
			kbl[i+1][j]=ks;
		}
	}
	maxth = 1;
	for(int i=1;i<=n;i++)
	{
		b[i-1]=0;
		for (int j = 0;j<n;j++)
		{
			if(kbl[i][j]==0)
			{
				b[i-1]++;
			}
		}
	}
	for (int i = 0;i<n;i++)
	{
		if(b[i] > maxth)
		{
			maxth = b[i];
		}
	}
	cout << maxth;
    return 0;
}
