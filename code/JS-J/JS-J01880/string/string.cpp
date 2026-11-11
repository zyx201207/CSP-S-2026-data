#include <bits/stdc++.h>
using namespace std;
long long n,m,k=1,gs[200005],ans,l,r;
char ch,a[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>ch;
        if(i==1)
        {
            gs[1]=m;
            a[1]=ch;
        }
        else
        {
            if(ch==a[k]) gs[k]+=m;
            else
            {
                k++;
                gs[k]=m;
                a[k]=ch;
            }
        }
    }
    if(k==1)
    {
        cout<<0;
        return 0;
    }
    l=1;r=k;
    while(l<r)
    {
        while(gs[l]==0)
        {
            l++;
        }
        while(gs[r]==0)
        {
            r--;
        }
        if(gs[l]==gs[r])
        {
            if(a[l]==a[r]) continue;
            else ans+=gs[l];
        }
        else if(gs[l]>gs[r])
        {
            ans+=gs[r];
            int t=gs[l]-gs[r],kk=1;
            while(t>0)
            {
                if(gs[r-kk]>=t)
                {
                    gs[r-kk]-=t;
                    ans+=t;
                    t=0;
                }
                else
                {
                    t-=gs[r-kk];
                    gs[r-kk]=0;
                    ans+=gs[r-kk];
                    kk++;
                }
            }
        }
        else if(gs[l]<gs[r])
        {
            ans+=gs[l];
            int t=gs[r]-gs[l],kk=1;
            while(t>0)
            {
                if(gs[l+kk]>=t)
                {
                    gs[l+kk]-=t;
                    ans+=t;
                    t=0;
                }
                else
                {
                    t-=gs[l+kk];
                    ans+=gs[l+kk];
                    gs[l+kk]=0;
                    kk++;
                }
            }
        }
        l++;r--;
    }
    cout<<ans;
    return 0;
}
