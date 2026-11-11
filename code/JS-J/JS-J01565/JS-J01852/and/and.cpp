#include <bits/stdc++.h>
using namespace std;
int n,m,maxx=INT_MIN,ma=INT_MIN,tot;
int a[500005];
int b[500005];
bool vis[500005];
void dfs(int cnt,int p)
{
    if(p==m)
    {
        ma=max(ma,cnt);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs((cnt&a[i]),p+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        maxx=max(maxx,a[i]);
        if(i==1)
            tot=a[1];
        else
            tot=(tot&a[i-1]);
    }
    if(n<=20)//1-5
    {
        dfs(2147483647,0);
        cout<<ma<<endl;
    }
    if(n>20&&n<=2000)//6-10
    {
        if(m==1)
            cout<<maxx<<endl;
        if(m==n)
            cout<<tot<<endl;
        if(m==2)
        {
            int maxx2=INT_MIN;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    int t=(a[i]&a[j]);
                    maxx2=max(maxx2,t);
                }
            }
            cout<<maxx2;
        }
    }
    return 0;
}
