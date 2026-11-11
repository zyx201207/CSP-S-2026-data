#include<bits/stdc++.h>
using namespace std;

#define int long long
int man=1e18+2;
const int mm=5e5+2;
    int ar[mm];
    int n,m;
bool check(int mid)
{
    int usee=ar[mid];
    int cnt=0;
    for(int i=1;i<=mid;i++)
    {
        cnt+=usee-ar[i];
        if(cnt>m)
        {
            return 0;
        }
    }
    return 1;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    sort(ar+1,ar+n+1);

    int mid;
    int lf=1,ri=n;
    while(lf<ri)
    {
        mid=(lf+ri)/2;
        if(check(mid))
        {
            lf=mid+1;
            ans=mid;
        }
        else
        {
            ri=mid-1;
        }
    }
    cout<<ans;
    return 0;
    
}
