#include <bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m,ans=0;
int a[N];
int b[N],cnt=0;
int c[N],k;
int get(int x,int y)
{
    return ((x>>y)&1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=n;i++)b[++cnt]=a[i];
    for (int j=30;j>=0;j--)
    {
        int res=0;
        for (int i=1;i<=cnt;i++)
            if (get(b[i],j))
                res++;
        if (res>=m)
        {
            ans+=(1<<j);
            k=0;
            for (int i=1;i<=cnt;i++)
                if (get(b[i],j))
                    c[++k]=b[i];
            cnt=k;
            for (int i=1;i<=cnt;i++)b[i]=c[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}