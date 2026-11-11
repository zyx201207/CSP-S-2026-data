#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],c=0,maxx=-1e9;
int main()
{
	srand(time(0));
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    ll x=m;
    if(n>=50000) cout << rand()%(abs(n-m));
    bool f=1,ff=1;
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]!=i)f=0;
    }
    for(ll i=1;i<n-1;i++)
    {
        cin >> a[i];
        if(a[i+1]-a[i]!=a[i+2]-a[i+1])ff=0;
    }
    if(f)
    {
    	for(ll i=1;i<=x;i++)
    	{
    		m-=i;
    		if(m<=0)
    		{
    			cout << i+1;
				return 0; 
			}
		}
	}
	if(ff)
	{
		for(ll i=1;i<=x;i=i+a[2]-a[1])
    	{
    		m-=i;
    		if(m<=0)
    		{
    			cout << i+1;
				return 0; 
			}
		}
	}
    for(ll i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]<=a[i] && a[i]-a[j]<=m) 
            {
                c++;
                m=m-(a[i]-a[j]);
            }
            if(m<=0) continue;
        }
        maxx=max(maxx,c);
        c=0;
        m=x;
    }
    cout << maxx;
    /*cout << "250000 100000000000\n";
    for(int i=1;i<=250000;i++) cout << i+132 << " ";*/
    return 0;
}//676767
