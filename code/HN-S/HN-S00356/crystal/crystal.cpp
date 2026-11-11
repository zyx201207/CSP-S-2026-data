#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++)
	    cin>>a[i];
	long long to=0;
	long long m1=0;
	long long maxx=0;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		to=0;
		m1=0;
		for(int j=i;j>=0;j--)
		{
			if(m1+abs(a[i]-a[j])<=m)
			{
				m1+=abs(a[i]-a[j]);
				to++;
			}
			else
			    break;
		}
		maxx=max(maxx,to);
    }
	cout<<maxx;
	return 0;
}
