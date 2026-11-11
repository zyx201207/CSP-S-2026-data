#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
long long n,m;
int cmp(long long a,long long b)
{
	return a < b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	vector<long long> a(n + 1);
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
    }
	sort(a.begin() + 1,a.begin() + n + 1,cmp);
	long long sum = m;
	long long num = 0;
	if(n == 1)
	{
		cout<<1;
		return 0;
	}
	long long maxn = -99999;
	for(int j = 2;j <= n;j++)
	{
		num = 0;
		sum = m;
	    for(int i = j;i >= 1;i--)
	    { 
		    if(sum - (a[j] - a[i]) >= 0)
		    {
				sum -= a[j] - a[i];
	    		num++;
		    }
	    }
	   for(int i = j + 1;i <= n;i++)
	    {
	    	if(a[i] == a[j])
		    {
		        num++;
		    }
		   if(a[i] > a[j])
		   {
			   break;
		   }
	    }
		if(num > maxn)
		{
			maxn = max(num,maxn);
		}
	}
	cout<<maxn<<'\n';
	return 0;
}
