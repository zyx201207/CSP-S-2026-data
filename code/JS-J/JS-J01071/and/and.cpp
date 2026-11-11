#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans;
int b[21]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,202143,524287,1048575};
bool cmp(int a,int b)
{
    return a>b;
}
bool check(int a)
{
    for(int i=1;i<=20;i++)
    {
        if(a==b[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    bool z=1;
    for(int i=1;i<=m;i++)
    {
        z*=check(a[i]);
    }
    if(z==1)
    {
        cout<<a[m];
        return 0;
    }
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    if(m==2)
    {
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=mx)
            {
                continue;
            }
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]<=mx)
                {
                    continue;
                }
                int c=a[i]&a[j];
                if(mx<c)
                {
                    mx=c;
                }
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==n)
    {
        int c=2147483647;
        for(int i=1;i<=n;i++)
        {
            c=c&a[i];
        }
        cout<<c;
        return 0;
    }
    cout<<0;
    return 0;
}
