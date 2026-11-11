#include<bits/stdc++.h>
using namespace std;
int n,m;
long long b[200001];
int h1[40];
struct tDot
{
    int id;
    int mw;
    int cnt;
    int x[31];
};
int c;
tDot a[200001];
int tx[40];
void v(int k)
{
    a[k].id = k;
    a[k].cnt = 0;
    int w=0;
    int t=b[k];
    while(t!=0)
    {
        int g=t%2;
        w++;
        t /= 2;
        if(g==1)
        {
            a[k].cnt++;
        }
        tx[w] = g;
    }
    for(int i=1;i<=w;i++)
    {
        a[k].x[i] = tx[i];
    }
    a[k].mw = w;
    return ;
}
bool cmp(tDot a,tDot b)
{
    if(a.mw==b.mw)
    {
        return a.id<b.id;
    }
    return a.mw>b.mw;
}
int k;
int h[200001];
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(h[a[i].id]==1)
        {
            c++;
        }
    }
    if(c==m)
    {
        return 1;
    }
    return 0;
}
void print()
{
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(h[a[i].id]==1)
        {
            if(ans==-1)
            {
                ans = b[a[i].id];
            }
            else
            {
                ans = ans&b[a[i].id];
            }
        }
    }
    cout<<ans;
    return ;
}
bool cmp1(tDot a,tDot b)
{
    return a.cnt<b.cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        v(i);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i].mw;j++)
        {
            if(a[i].x[j]==1)
            {
                h1[j]++;
             //   cout<<j<<" ";
            }
        }
    }
    /*
    for(int i=31;i>=1;i--)
    {
        cout<<h1[i]<<" ";
    }
    cout<<'\n';
    */
    for(int i=31;i>=1;i--)
    {
        if(h1[i]>=m)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j].x[i]==1)
                {
                    h[a[j].id] = 1;
                }
            }
            k = i;
            break;
        }
    }
    for(int i=k-1;i>=1;i--)
    {
        if(h1[i]>=m)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(h[a[j].id]==1)
                {
                    if(a[j].x[i]==1)
                    {
                        cnt++;
                    }
                }
            }
            if(cnt>=m)
            {
                for(int j=1;j<=n;j++)
                {
                    if(h[a[j].id]==1)
                    {
                        if(a[j].x[i]!=1)
                        {
                            h[a[j].id] = 0;
                        }
                    }
                }
            }
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<a[i].id<<'\n';
        cout<<b[a[i].id]<<'\n';
        cout<<a[i].mw<<'\n';
    }
    for(int i=1;i<=n;i++)
    {
        cout<<h[a[i].id]<<" ";
    }
    */
    if(check())
    {
        print();
    }
    else
    {
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++)
        {
            if(h[a[i].id]==1)
            {
                h[a[i].id] = 0;
                c--;
                if(c==m)
                {
                    break;
                }
            }
        }
        print();
    }
    return 0;
}
