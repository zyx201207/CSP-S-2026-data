#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m;
ll a[N];
ll ee[N];
ll cha[N];
bool check(int k)//k:buchang
{

    ll s=ee[k];
    for (int i=1;i+k-1<=n;i++)
    {
        //if (k==315276)
         //   cout<<i<<' '<<s<<'\n';
        if (s<=m)
            return 1;
        s-=a[i+k-1]-a[i];
        s+=(k-1)*cha[i+k];
    }
    //if (s<=m)
     //   return 1;
    return 0;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    cha[1]=a[1];
    for (int i=2;i<=n;i++)
        cha[i]=a[i]-a[i-1];
    for (int i=1;i<=n;i++)
        ee[i]=ee[i-1]+(i-1)*(a[i]-a[i-1]);
    /*for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<'\n';
    for (int i=1;i<=n;i++)
        cout<<cha[i]<<' ';
    cout<<'\n';
    for (int i=1;i<=n;i++)
        cout<<ee[i]<<' ';
    cout<<'\n';*/
    //cout<<m<<'\n';
    int l=1,r=n;
    int k=(l+r)>>1;
    while (l+10<r)
    {
        k=(l+r)>>1;
        //cout<<l<<' '<<r<<' '<<"mid="<<k<<' '<<check(k)<<'\n';
        if (check(k))
        {
            l=k;
        }
        else
        {
            r=k-1;
        }
    }
    //cout<<check(315275);
    for (int i=r;i>=l;i--)
    {
        //cout<<"k="<<i<<'\n';
        if (check(i))
        {
            /*for (int j=1;j<=i;j++)
            {

                if (!check(j))
                {
                    cout<<"hyw";
                    cout<<j;
                }
            }
            for (int j=i+1;j<=n;j++)
            {

                if (check(j))
                {
                    cout<<"hyw";
                    cout<<j;
                }
            }*/
            cout<<i;
            return 0;
        }
    }
    cout<<"114514";
    //kongbeiqie
    return 0;
}
/*
16:16

4
1 2 2
1 3 5
2 4 1
2 3 2

*/
