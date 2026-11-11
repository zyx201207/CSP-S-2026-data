#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+5;
int n,m;
ll a[MAXN];
bool ch(int x)
{
    ll c=m;
    for(int i=x-1;i>=1;i--)
    {
        c-=a[x]-a[i];
    }
    if(c>0)return 1;
    return 0;
}
bool ch1(int x)
{
    if(m>a[x]-a[x-1])return 1;
    return 0;
}
void sol()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<=5000)
    {
        ll ans=0;
        ll b[5002]{};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                b[j]=abs(a[i]-a[j]);
            }
            sort(b+1,b+1+n);
            ll cnt=0;
            int c=m;
            for(int i=1;i<=n&&c-b[i]>=0;i++)
            {
                c-=b[i];
                cnt++;
            }
            ans=max(cnt,ans);
        }
        cout<<ans;
        return;
    }
    ll ans=-1;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(ch(mid))
        {
            l=mid+1;
            ll c=m;
            ll cnt=1;
            for(int i=mid-1;i>=1;i--)
            {
                if(c-(a[mid]-a[i])<0)break;
                c-=(a[mid]-a[i]);
                cnt++;
            }
            for(int i=mid+1;i<=n;i++)
            {
                if(a[i]==a[mid])cnt++;
                else break;
            }
            ans=max(ans,cnt);
            //cout<<cnt<<" ";
        }
        else
        {
            if(ch1(mid))
            {
                ll c=m;
                ll cnt=1;
                for(int i=mid-1;i>=1;i--)
                {
                    if(c-(a[mid]-a[i])<0)break;
                    c-=(a[mid]-a[i]);
                    cnt++;
                }
                for(int i=mid+1;i<=n;i++)
                {
                    if(a[i]==a[mid])cnt++;
                    else break;
                }
                ans=max(ans,cnt);
                //cout<<cnt<<" ";
            }
            r=mid-1;
        }
    }
    cout<<ans;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;//cin>>T;
    while(T--)sol();
    return 0;
}
