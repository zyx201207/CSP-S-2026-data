#include <bits/stdc++.h>
using namespace std;

const int M=2e5+5;
char c[M];
int a[M];

struct Node
{
    int a;
    char c;
} ;
Node l[M],r[M];


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        sum+=a[i];
    }
    if (sum%2==1)
    {
        long long mid=(sum+1)/2,ans=0;
        long long nowcur=1;int temp;bool flag=0;
        for (int i=1;i<=n;i++)
        {
            nowcur+=a[i];
            if (nowcur>mid)
            {
                temp=i;
                l[i].a=a[i]-(nowcur-mid);
                l[i].c=c[i];
                if (nowcur-mid==0) break;
                r[1].a=nowcur-mid-1;
                flag=1;
                r[1].c=c[i];
                break;
            }
            else
            {
                l[i].a=a[i];
                l[i].c=c[i];
            }
        }
        for (int i=temp+1;i<=n;i++)
        {
            r[i-temp+1].a=a[i];
            r[i-temp+1].c=c[i];
        }
        long long lnow=1,rnow=1;
        while (lnow<=temp||rnow<=n-temp+flag)
        {
            if (l[lnow].c==r[rnow].c)
            {
                if (l[lnow].a<r[rnow].a)
                {
                    r[rnow].a-=l[lnow].a;lnow++;
                }
                else if (l[lnow].a==r[rnow].a)
                {
                    lnow++;rnow++;
                }
                else
                {
                    l[lnow].a-=r[rnow].a;rnow++;
                }
            }
            else
            {
                if (l[lnow].a<r[rnow].a)
                {
                    r[rnow].a-=l[lnow].a;
                    ans+=l[lnow].a;
                    lnow++;
                }
                else if (l[lnow].a==r[rnow].a)
                {
                    ans+=l[lnow].a;
                    lnow++;rnow++;
                }
                else
                {
                    l[lnow].a-=r[rnow].a;
                    ans+=r[rnow].a;
                    rnow++;
                }
            }
        }
        cout << ans;
        return 0;
    }
    else
    {
        long long mid=sum/2,ans=0;
        long long nowcur=0;int temp;bool flag=0;
        for (int i=1;i<=n;i++)
        {
            nowcur+=a[i];
            if (nowcur>mid)
            {
                temp=i;
                l[i].a=a[i]-(nowcur-mid);
                l[i].c=c[i];
                if (nowcur-mid==0) break;
                r[1].a=nowcur-mid;
                flag=1;
                r[1].c=c[i];
                break;
            }
            else
            {
                l[i].a=a[i];
                l[i].c=c[i];
            }
        }
        for (int i=temp+1;i<=n;i++)
        {
            r[i-temp+1].a=a[i];
            r[i-temp+1].c=c[i];
        }
        long long lnow=1,rnow=1;
        while (lnow<=temp||rnow<=n-temp+flag)
        {
            if (l[lnow].c==r[rnow].c)
            {
                if (l[lnow].a<r[rnow].a)
                {
                    r[rnow].a-=l[lnow].a;lnow++;
                }
                else if (l[lnow].a==r[rnow].a)
                {
                    lnow++;rnow++;
                }
                else
                {
                    l[lnow].a-=r[rnow].a;rnow++;
                }
            }
            else
            {
                if (l[lnow].a<r[rnow].a)
                {
                    r[rnow].a-=l[lnow].a;
                    ans+=l[lnow].a;
                    lnow++;
                }
                else if (l[lnow].a==r[rnow].a)
                {
                    ans+=l[lnow].a;
                    lnow++;rnow++;
                }
                else
                {
                    l[lnow].a-=r[rnow].a;
                    ans+=r[rnow].a;
                    rnow++;
                }
            }
        }
        cout << ans;
        return 0;
    }
    return 0;
}
