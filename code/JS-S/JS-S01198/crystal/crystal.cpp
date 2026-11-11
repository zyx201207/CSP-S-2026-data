#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int ch[500010];
int q[500010];
bool f=0;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i =1;i <= n;i++)
    {
        cin>>a[i];
        if(a[i]>100)
        {
            f=1;
        }
    }
    sort(a+1,a+n+1);
    if(n<=5000)
    {
        int maxn = 0;
    for(int i = 1;i <= n;i++)
    {
        int x=m;
        int now=a[i];
        int cur=i;
        int cnt=0;
        while(x>=0&&cur>0)
        {
            int ca=now-a[cur];
            if(x>=ca)
            {
                x-=ca;
                cnt++;
            }
            else{
                break;
            }
            cur--;
        }
        maxn=max(maxn,cnt);
    }
    cout << maxn;
    }
    else if(n>=5000&&f)
    {
        int cha=a[2]-a[1];
        int u=1;
        int o=m;
        int cnt = 1;
        while(o>0&&cnt<=n)
        {
            if(o>=(u*cha))
            {
                o-=(u*cha);
                cnt++;
                u++;
            }
            else{
                break;
            }
        }
        cout<<min(cnt,n);
    }
    else{

        for(int i= 2;i <= n;i++)
    {
        ch[i]=a[i]-a[i-1];
    }
    for(int i= 2;i <= n;i++)
    {
        q[i]=q[i-1]+(i-1)*ch[i];
    }
    int maxn = 0;
    for(int i = 1;i <= n;i++)
    {
        if(q[i]<=m)
        {
            maxn=i;
        }

    }
    int x=m;
        int now=a[maxn+1];
        int cur=maxn+1;
        int cnt=0;
        while(x>=0&&cur>0)
        {
            int ca=now-a[cur];
            if(x>=ca)
            {
                x-=ca;
                cnt++;
            }
            else{
                break;
            }
            cur--;
        }
        maxn=max(maxn,cnt);
    cout << maxn;
    }






    return 0;
}
//last
