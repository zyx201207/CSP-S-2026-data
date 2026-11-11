#include <bits/stdc++.h>
using namespace std;
long long n,lenn,ans,huanl,opi;
int le,ri;
long long lnum,rnum;
char lc,rc;
struct oocc
{
    long long l;
    char c;
};
oocc a[200100];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].c;
        lenn+=a[i].l;
    }
    for(int i=1;i<=n;i++)
    {
        huanl+=a[i].l;
        if(huanl>=lenn/2)
        {
            opi=i;
            break;
        }
    }
    le=1;
    ri=n;
    lnum=a[le].l;
    lc=a[le].c;
    rnum=a[ri].l;
    rc=a[ri].c;
    while(le<=opi and ri>=opi)
    {
        if(lnum==0)
        {
            le++;
            lnum=a[le].l;
            lc=a[le].c;
            continue;
        }
        if(rnum==0)
        {
            ri--;
            rnum=a[ri].l;
            rc=a[ri].c;
            continue;
        }
        if(lnum==rnum)
        {
            if(rc!=lc) ans+=rnum;
            lnum=0;
            rnum=0;
        }
        else if(lnum>rnum)
        {
            if(rc!=lc) ans+=rnum;
            lnum-=rnum;
            rnum=0;
        }
        else
        {
            if(rc!=lc) ans+=lnum;
            rnum-=lnum;
            lnum=0;
        }
    }
    cout<<ans;
    return 0;
}
