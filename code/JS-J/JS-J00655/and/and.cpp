#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
int n,m;
int a[MAXN];
bool useful[MAXN];
int cnt=0;
int ans=0;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        useful[i]=true;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=30;i>=0;i--)
    {
        cnt=0;
        for(int x=1;x<=n;x++)
        {
            if(useful[x]&&(a[x]&(1<<i)))
            {
                cnt++;
            }
        }
        if(cnt>=m)
        {
            ans|=(1<<i);
            for(int x=1;x<=n;x++)
            {
                if(!(a[x]&(1<<i)))
                {
                    useful[x]=false;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}