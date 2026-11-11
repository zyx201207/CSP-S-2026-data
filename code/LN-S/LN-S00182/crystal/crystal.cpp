#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=(int)(5e5+10);

int n,m;
int a[N];int c[N], b[N];int allcost[N];int preb[N];
int maxn=INT_MIN;

bool cmp(int rr, int rj)
{
    return (rr < rj) ? 1 : 0 ;
}

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);


    scanf("%lld%lld", &n, &m);
    for(int i=1;i<=n;i++)scanf("%lld", &a[i]);
    sort(a+1, a+n+1, cmp);
    //for(int i=0;i<n;i++)cout<<a[i]<<' ';\

    for(int i = 1;i <= n;i ++)
    {
        b[i]=b[i-1]+a[i];
    }


    int l=1;
    for(int r=1;r<=n;++r)
    {
        while(l<=r)
        {
            int lenth=r-l+1;
            int sum=b[r]-b[l-1];
            int cost=a[r]*lenth-sum;
            if(cost<=m)break;
            ++l;
        }
        maxn=max(maxn, r-l+1);
    }
    /*
    for(int i=1;i<=n;i++)cout<<b[i]<<' ';
    cout<<endl<<endl;
    */
    printf("%lld", maxn);
    /*
    for(int i=0;i<n;i++)cout<<allcost[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++)cout<<b[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++)cout<<preb[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++)cout<<c[i]<<' ';
    cout<<endl;
    */
    return 0;
}
