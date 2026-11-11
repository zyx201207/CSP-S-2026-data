#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ma_x=1,x=0;
	cin>>n>>m;
	long long a[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		x=0;
		//cout<<i;
		for(int j=i;j>=0;j--)
		{
			int m1=m-(a[i]-a[j]);
			if(m1>0&&m1>=0)
			{
				x++;
		//		cout<<" "<<a[j];
			}
		}
	//	cout<<endl;
		ma_x=max(x,ma_x);
	}
	cout<<ma_x;
	return 0;
} 
