#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e6+10;
int a[maxn];
char c[maxn];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    int wl=0,wr=0;
    while(l<r)
    {
        wl+=a[l];
        a[l]=0;
        wr+=a[r];
        a[r]=0;
        int w=min(wl,wr);
        wl-=w;
        wr-=w;
        if(c[l]!=c[r])ans+=w;
        if(wl==0)l++;
        if(wr==0)r--;
    }
    cout<<ans;
    //bu yao a;
    return 0;
}
