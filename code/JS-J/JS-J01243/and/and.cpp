#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[200005];
int a[200005][35];
int c[35];
long long k[200005];
int d[200005];
void work(long long x,int xx)
{
    long long kk;
    int h=0;
    while(x!=0)
    {
        h++;
        kk=x%2;
        if(kk==1)
        {
            a[xx][h]=1;
            c[h]++;
        } 
        x/=2;
    }
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
        cin>>k[i];
        work(k[i],i);
    }
    int f=0,s=30;
    while(c[s]<m&&s>0) s--;
    if(s==0) 
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i][s]==1) b[i]=1;
    }
    int t=s;
    int ansx=c[s];
    int ans=0;
    while(f==0&&s>0)
    {
        s--;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][s]==0&&b[i]==1) d[i]=1,ans++;
        }
        if(ansx-ans>=m) 
        {
            for(int i=1;i<=n;i++)
            {
                if(b[i]==1&&d[i]==1) b[i]=0;
                d[i]=0;
            }
            ansx-=ans;
        }
        if(ansx==m)
        {
            long long ansxx=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i]==1)
                {
                    if(ansxx==0) ansxx=k[i];
                    else ansxx=ansxx&k[i];
                }
            }
            cout<<ansxx;
            f=1;
        }
    }
    if(f==0)
    {
        long long ansxxx=0,js=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i]==1) 
            {
                if(ansxxx==0) ansxxx=k[i];
                else ansxxx=ansxxx&k[i];
                js++;
            }
            if(js==m) break;
        }
        cout<<ansxxx;
    }
    return 0;
}