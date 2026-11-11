#include<bits/stdc++.h>
using namespace std;
int vis[1005];
int a[200005];
int ans=0;
int n,m;
int cnt=0;
void f(int i,int step)
{
    if(i==n+1 && step==m+1)
    {
        int h=vis[1];
        for(int i=1;i<=m;i++)
        {
            h=h&vis[i];
            //cout << vis[i] << ' ';
        }
        //cout << endl;
        ans=max(ans,h);
        return ;
    }
    if(i==n+1)return;
    if(step>m+1)return ;
    cnt++;
    vis[cnt]=a[i];
    f(i+1,step+1);
    cnt--;
    f(i+1,step);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    if(n<=20)
    {
        cnt=0;
        for(int j=1;j<=n;j++)vis[j]=0;
        f(1,1);
        cout << ans;
    }
    else if(m==1)
    {
        cout << a[n];
    }
    else if(m==2)
    {
        int anss=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {

                if(i!=j)
                {
                    anss=max(anss,i&j);
                }
            }
        }
        cout << anss;
    }
    else if(n==m)
    {
        for(int i=1;i<=n;i++)
        {
            a[1]&=a[i];
        }
        cout << a[1];
    }
    else cout << 3;
    return 0;
}
//2147483647
