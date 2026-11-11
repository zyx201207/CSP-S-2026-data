#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int si;
    char id;
};
node t[200010],a[200010],b[200010];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> t[i].si >> t[i].id;
        sum+=t[i].si;
    }
    int po=0,sn=0;
    while(sn+t[po+1].si<=(sum+1)/2)
    {
        po++;
        sn+=t[po].si;
        a[po].si=t[po].si;
        a[po].id=t[po].id;
    }
    int pob=n+1,snb=0;
    a[po+1].si=(sum+1)/2-sn;
    a[po+1].id=t[po+1].id;
    t[po+1].si-=((sum+1)/2-sn);
    while(snb+t[pob-1].si<=sum/2)
    {
        pob--;
        snb+=t[pob].si;
        b[n-pob+1].si=t[pob].si;
        b[n-pob+1].id=t[pob].id;
    }
    int lena=po+1;
    int lenb=n-pob+1;
    int pa=1,pb=1,ans=0;
    while(1)
    {
        if(a[pa].id!=b[pb].id)
        {
            int te=min(a[pa].si,b[pb].si);
            a[pa].si-=te;
            b[pb].si-=te;
            ans+=te;
        }
        else
        {
            int te=min(a[pa].si,b[pb].si);
            a[pa].si-=te;
            b[pb].si-=te;
        }
        if(a[pa].si<=0)
        {
            pa++;
        }
        if(b[pb].si<=0)
        {
            pb++;
        }
        if(pa>lena||pb>lenb)
        {
            break;
        }
    }
    cout << ans;
    return 0;
}