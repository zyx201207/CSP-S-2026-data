#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n;
long long l,ans;
struct id
{
    long long bg=0;
    long long ed=0;
    char num;
}h[N];
long long fd_(long long tar,int ok)
{
    long long l=1,r=n;
    if (!ok)
    {
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if (h[mid].ed>tar) r=mid;
            else l=mid+1;
        }
        return l;
    }
    else
    {
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if (h[mid].bg>tar) r=mid-1;
            else l=mid;
        }
        return l;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        h[i].bg=h[i-1].ed+1;
        h[i].ed=h[i-1].ed+k;
        cin>>h[i].num;
        l+=k;
    }
    for (int i=1;i<=n;i++)
    {
        long long tarb=l-h[i].ed+1,tard=l-h[i].bg+1;
        char tarn=h[i].num;
        if (tard<=l/2) break;
        for (int j=n;j>=1;j--)
        {
            if (h[j].bg<=tard&&h[j].ed>=tarb)
            {
                if (h[j].num!=tarn) ans+=min(tard,h[j].ed)-max(tarb,h[j].bg)+1;
            }
            if (h[j].ed<tarb) break;
        }
    }
    cout<<ans;
    return 0;
}
