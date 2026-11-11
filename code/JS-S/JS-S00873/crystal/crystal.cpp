#include <bits/stdc++.h>
using namespace std;
long long a[500005], d=1, f=1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	sort(a+1, a+1+n);
	int z=(n+1)/2;
	int pos1=z-1;
	int pos2=z+1;
	int sum=0;
	a[0]=1e18;
	a[n+1]=-1e18;
	while(m-min(a[z]-a[pos1], a[pos2]-a[z])>=0)
	{
		if((pos1<=0&&pos2<=n)&&(m-(a[pos2]-a[z])>=0))
		{
			m-=a[pos2]-a[z];
			pos2++;
			sum++;
		}
		else if((pos1>0&&pos2>n)&&(m-(a[z]-a[pos1])>=0))
		{
			m-=a[z]-a[pos1];
			pos1--;
			sum++;
		}
		else if(pos1<=0&&pos2>n) break;
		else if(a[z]-a[pos1]<=a[pos2]-a[z])
		{
			m-=a[z]-a[pos1];
			pos1--;
			sum++;
		}
		else
		{
			m-=a[pos2]-a[z];
			pos2++;
			sum++;
		}
	}
	cout<<sum+1<<endl;
	return 0;
}
