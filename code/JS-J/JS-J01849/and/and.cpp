#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxn=0;
int maxx=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    cin >> a[1];
    maxn=a[1];
    int x=a[1];
    for(int i=2;i<=n;i++)
    {
        cin >> a[i];
        maxn=max(a[i],maxn);
        x=x&a[i];
    }
    if(m=1)
    {
        cout << maxn;
        return 0;
    }
    if(n==m)
    {
        cout << x;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxx=max(a[i] & a[j],maxx);
            }
        }
        cout << maxx;
    }
    return 0;
}
