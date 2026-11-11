#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,sum=0,maxx=-1;
bool pd(long long mid)
{
	sum=0;
    int m1=m;
    for(int i=1;i<=mid;i++)
    {
        if(m1>=a[mid]-a[i])
        {
            m1-=(a[mid]-a[i]);
            sum++;
        }
        else
        {
        	m=-1;
            break;
        }
    }
    maxx=max(maxx,sum);
    return maxx;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)
        	flag=0;
	}
	if(flag)
	{
		sum=1;
		long long p=0;
		while(++p)
		{
			m-=p;
			sum++;
		}
		cout<<sum;
		return 0;
	}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        pd(i);
    }
    cout<<maxx;
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
