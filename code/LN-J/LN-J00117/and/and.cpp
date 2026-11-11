#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool w[200005][32];
int len[32];
string ans;
int n,m;
long long st=0;
void dfs(long long cl[],int st,int cnt)
{
    if(st==0)
    {
        return;
    }
    memset(len,0,sizeof len);
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=32;j++)
        {
            w[i][j]=0;
        }
    }
    bool flag=0;
    for(int i=1;i<=cnt;i++)
    {
        for(int j=st;j>=1;j--)
        {
            //cout<<1;
            w[i][j]=((cl[i]>>j)&1);
            if(w[i][j])
            {
                len[j]++;
            }
        }
    }
    for(int i=st;i>=1;i--)
    {
        if(len[i]>=m)
        {
            st=i;
            flag=1;
            break;
        }
    }
    if(flag)
    {
        //cout<<1;
        ans[st]=1;
    }
    else
        dfs(cl,st-1,cnt);
    for(int i=1;i<=cnt;i++)
    {
        if(w[i][st])
        {
            cl[++cnt]=a[i];
        }
    }
    dfs(cl,st-1,cnt);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long anss=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        for(int i=1;i<=n;i++)
        {
            anss&=a[i];
        }
        cout<<anss;
        return 0;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            anss=max(anss,a[i]);
        }
        cout<<anss;
        return 0;
    }
    dfs(a,32,n);
    cout<<ans<<'\n';
    return 0;
}