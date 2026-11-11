#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=-1;
int c[200005],d[200005],e[200005];
int tmp=0;
int And(int a,int b)
{
    int f=0,k=0;
    while(a!=0)
    {
        c[++f]=a%2;
        a/=2;
    }
    while(b!=0)
    {
        d[++k]=b%2;
        b/=2;
    }
    if(k<f)
    {
        for(int i=f;i>k;i--)
        {
            d[i]=0;
        }
    }
    for(int i=f;i>=1;i--)
    {
        if(d[i]==c[i] && d[i]!=1)
        {
            tmp+=pow(2,i-1);
        }
    }
    return tmp;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout << a[n];
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ans=max(ans,And(max(a[i],a[j]),min(a[i],a[j])));
            }
        }
        cout << ans;
    }
    return 0;
}
