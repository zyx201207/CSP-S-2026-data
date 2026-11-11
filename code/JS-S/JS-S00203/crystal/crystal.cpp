#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],cnt[N],c[N];
ll ans,nd,sum,cs[N];
bool A=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=i)A=0;
    }
    if(A)
    {
        for(int i=1;i<=n;i++)
        {
            if(i*(i-1)/2>m)
            {
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    sort(a+1,a+n+1);
    ll idx=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1]&&i!=1)
        {
            c[++idx]=a[i]-a[i-1];
        }
        cnt[idx]++;
    }
    for(int i=1;i<=idx;i++)
    {
        cs[i]=c[i]+cs[i-1];
    }
    ll q=1;
    for(int i=1;i<=idx;i++)
    {
        nd+=sum*c[i];
        sum+=cnt[i];
        while(nd>m&&q<=i)
        {
            nd-=cnt[q]*(cs[i]-cs[q-1]);
            sum-=cnt[q];
            q++;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    //cerr<<ans;
    return 0;
}
