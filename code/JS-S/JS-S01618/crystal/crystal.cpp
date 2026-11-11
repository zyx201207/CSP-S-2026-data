#include<bits/stdc++.h>
using namespace std;

long long a[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    unsigned long long s=0;
    int maxn=0;
    for(int i=1,j=1;j<=n;j++)
    {
        s+=(j-i)*(a[j]-a[j-1]);
        while(s>m)
        {
            s-=a[j]-a[i];
            i++;
        }
        maxn=max(maxn,j-i+1);
    }
    cout<<maxn;
    return 0;
}
