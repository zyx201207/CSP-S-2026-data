#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m,a[500005],b[500005],maxa,ans,cnt,x,y,mina;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
    }
    for(ll k=mina;k<=maxa+m;k++)
    {
        cnt=0;
        x=0;
        y=0;
        for(int i=1;i<=n;i++)
        {
            b[i]=k-a[i];
            if(b[i]>=0) cnt++;
            else b[i]=1e18+5;
        }
        if(cnt<=ans) continue;
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)
        {
            if(x+b[i]<=m) y++;
            else break;
        }
        ans=max(ans,y);
    }
    cout<<ans;
    return 0;
}
