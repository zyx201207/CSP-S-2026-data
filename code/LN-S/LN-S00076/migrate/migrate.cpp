#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[5005];
int ans[5005][5005];
int op;
void solve()
{
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int st=1;st+i<=n;st++)
        {
            for(int en=st+i;en<=n;en++)
            {
                if(i==0&&a[en]-a[st]>d)
                {
                    ans[st][en]=0;
                    continue;
                }
                int x=st;
                ans[st][en]=1;
                for(int k=1;k<=1<<(en-st+1);k++)
                {
                    int us=k;
                    for(int j=st;j<en;j++)
                    {
                        if(us&1&&ans[x][j]!=0)
                        {
                            ans[st][en]*=ans[x][j];
                            x=j;
                        }
                        us>>1;
                    }
                }
                if(ans[x][en]!=0)
                ans[st][en]*=ans[x][en];
                if(ans[st][en]==1)
                {
                    op++;
                }
            }
        }
    }
    cout<<op<<endl;
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
