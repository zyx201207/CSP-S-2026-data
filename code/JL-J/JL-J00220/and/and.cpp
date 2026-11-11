#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m,s;
const ll M=2e3+10;
ll a[M],dp[M][M];
bool cmp(ll a,ll b){return a>b;}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    bool f=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ll h=log2(a[i]+1)-(int)(log2(a[i]+1));
        h!=0?f=0:f;
    }
    if(m==1)
    {
        sort(a+1,a+1+n);
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        s=a[1];
        for(int i=2;i<=n;i++)
           s&=a[i];
        cout<<s;
        return 0;
    }
    if(f)
    {
        sort(a+1,a+1+n,cmp);
        cout<<a[m];
    }
    return 0;
}
//退役快乐！
