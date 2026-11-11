#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long maxn=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==1)
    {
        for(int i=1;i<=n;i++)
            maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=2;j<=n;j++)
            {
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n)
    {
        maxn=a[1];
        for(int i=2;i<=n;i++)
        {
            maxn&=a[i];
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1)
    {
        for(int i=1;i<=n;i++)
        {
            bool p=1;
            for(int j=1;j<=n;j++)
            {
                if(j!=i&&p)
                {
                    maxn=a[j];
                    p=0;
                    continue;
                }
                if(j!=i) maxn&=a[j];
            }
        }
        cout<<maxn;
        return 0;
    }
    sort(a+1,a+1+n);
    cout<<a[n-m+1];
	return 0;
}
