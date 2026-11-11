#include <bits/stdc++.h>
#define int long long
using namespace std;
struct zf
{
    int sl;
    char c;
}s[200010];
zf lc[200010],lcp[200010];
zf rc[200010],rcp[200010];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int len=0;
    for(int i= 1;i <= n;i++)
    {
        cin>>s[i].sl>>s[i].c;
        len+=s[i].sl;
    }
    int ban=0;
    if(len%2==0)
    {
        ban=len/2;
    }
    else{
        ban=(len-1)/2;
    }
    int x=ban;
    int cur=1;
    int lcn=0,rcn=0;
    while(x>0)
    {
        if(s[cur].sl<=x)
        {
            lcn++;
            lc[lcn].sl=s[cur].sl;
            lc[lcn].c=s[cur].c;
            x-=s[cur].sl;
        }
        else{
            lcn++;
            lc[lcn].sl=x;
            lc[lcn].c=s[cur].c;
            x=0;
        }
        cur++;

    }
    x=ban;
    cur=n;
    while(x>0)
    {
        if(s[cur].sl<=x)
        {
            rcn++;
            rc[rcn].sl=s[cur].sl;
            rc[rcn].c=s[cur].c;
            x-=s[cur].sl;
        }
        else{
            rcn++;
            rc[rcn].sl=x;
            rc[rcn].c=s[cur].c;
            x=0;
        }
        cur--;
    }
    for(int i = 1;i <= lcn;i++)
    {
        lcp[i].sl=lc[i].sl;
        lcp[i].c=lc[i].c;
    }
    for(int i = 1;i <= rcn;i++)
    {
        rcp[i].sl=rc[i].sl;
        rcp[i].c=rc[i].c;
    }
    cur=rcn;
    int lcc=0;
    for(int i = lcn;i>=1;i--)
    {
        int u=lc[i].sl;
        char nc=lc[i].c;
        while(u>0)
        {
            if(rcp[cur].sl<=u)
            {
                if(rcp[cur].c!=nc)
                {
                    lcc+=rcp[cur].sl;
                }
                u-=rcp[cur].sl;
                cur--;
            }
            else{
                if(rcp[cur].c!=nc)
                {
                    lcc+=u;
                }
                rcp[cur].sl-=u;
                u=0;

            }
        }
    }
    int rcc=0;
    cur=1;
    for(int i = 1;i <= rcn;i++)
    {
        int u=rc[i].sl;
        char nc=rc[i].c;
        while(u>0)
        {
            if(lcp[cur].sl<=u)
            {
                if(lcp[cur].c!=nc)
                {
                    rcc+=lcp[cur].sl;
                }
                u-=lcp[cur].sl;
                cur++;
            }
            else{
                if(lcp[cur].c!=nc)
                {
                    rcc+=u;
                }
                lcp[cur].sl-=u;
                u=0;

            }
        }
    }
    cout << min(lcc,rcc);
    return 0;
}
