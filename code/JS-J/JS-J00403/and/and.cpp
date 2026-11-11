#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005];
bool c[200005][33];
bool flag[200005],ans[33];

void ccc(int x)
{
    for(int i=0;i<=30;i++)
    {
        c[x][i]=0;
        if(a[x]%2==1)
        {
            c[x][i]=1;
        }
        a[x]/=2;
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        flag[i]=1;
        cin>>a[i];
        ccc(i);
    }
    for(int i=30;i>=0;i--)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(!flag[j])
            {
                continue;
            }
            if(c[j][i]==1)
            {
                cnt++;
            }
        }
        if(cnt>=m)
        {
            ans[i]=1;
            for(int j=1;j<=n;j++)
            {
                if(!flag[j])
                {
                    continue;
                }
                if(c[j][i]==0)
                {
                    flag[j]=0;
                }
            }
        }
        else
        {
            ans[i]=0;
        }
    }
    int cnt=0,now=1;
    for(int i=0;i<=30;i++)
    {
        if(ans[i])
        {
            cnt+=now;
        }
        now*=2;
    }
    cout<<cnt;
    return 0;
}
