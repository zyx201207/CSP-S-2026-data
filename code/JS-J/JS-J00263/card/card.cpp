#include<bits/stdc++.h>
using namespace std;
int g[100000]={0},ans[100000]={0};
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>g[i];
    }
    for(int i=1;i<=n;i++)
    {
        int t[100000]={0},tp=1,kp;
        for(int j=i;j<=n;j++)
        {
            int f=1;
            for(int k=1;k<tp;k++)
            {
                if(t[k]==g[j])
                {
                    f=0;
                    kp=k;
                    break;
                }
            }
            if(f==1)
            {
                t[tp]=g[j];
                tp++;
            }
            else
            {
                for(int k=kp;k<tp;k++)
                {
                    t[k]=0;
                }
                tp=kp;
                t[tp]=g[j];
                tp++;
            }
        }
        for(int j=1;j<=tp;j++)
        {
            ans[t[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
