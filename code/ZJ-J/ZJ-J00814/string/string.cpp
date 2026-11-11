#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005];
char c[200005];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    ll l=1,r=n+1,cl=c[1],cr=0,nl=a[1],nr=0;
    ll ans=0;
    while(l<r)
    {
        int o=ans;
        if(nl>nr)
        {
            r--;
            if(l==r)break;
            if(c[r]!=cl)
            {
                if(nl>nr+a[r])ans+=a[r];else ans+=nl-nr;
            }
            cr=c[r],nr+=a[r];
        }
        else
        {
            l++;
            if(l==r)break;
            if(c[l]!=cr)
            {
                if(nr>nl+a[l])ans+=a[l];else ans+=nr-nl;
            }
            cl=c[l],nl+=a[l];
        }
    }
    cout<<ans<<"\n";
    return 0;
}