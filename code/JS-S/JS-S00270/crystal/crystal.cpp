#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
int n;
bool vis=1;
ll m;
ll a[N];
int maxn=1;
bool vis2=1;
int dengcha;
void solve1()
{
    int ans=0;
    ll x=m;
    int cnt=n;
    int q=0;
    while (x>0&&cnt>0)
    {
        if (x-q>=0)
        {
            x-=q;
            cnt--;
            q+=1;
            ans+=1;
        }
        else break;
    }
    cout<<ans;
}

void solve2()
{
    int ans=0;
    ll x=m;
    int cnt=n;
    int q=0;
    while (x>0&&cnt>0)
    {
        if (x-q>=0)
        {
            x-=q;
            cnt--;
            q+=dengcha;
            ans+=1;
        }
        else break;
    }
    cout<<ans;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (a[i]!=i) vis=0;
    }
    if (vis==1) {solve1();return 0;}
    sort(a+1,a+n+1);

    dengcha=a[2]-a[1];
    for (int i=2;i<=n;i++) if (a[i]-a[i-1]!=dengcha) vis2=0;
    if (vis2==1) {solve2();return 0;}

    for (int i=n;i>=1;i--)
    {
        int cnt=i;
        ll x=m;
        int ans=0;
        while (x>=0&&cnt>0)
        {
            if (x>=a[i]-a[cnt])
            {
                ans+=1;
                x=x-(a[i]-a[cnt]);
                cnt--;
            }
            else break;
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}
