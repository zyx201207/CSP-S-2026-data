#include<bits/stdc++.h>
using namespace std;
bool erj[200006][33],ans2[33];
int ge0[33],aaa[200006];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0,xxx=1;
    cin>>n>>m;
    int nm=n-m;
    for (int i=1;i<=n;i++)
    {
        cin>>aaa[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<30;j++)
        {
            if (aaa[i]%2==1) erj[i][j]=1;
            else ge0[j]++;
            aaa[i]/=2;
        }
    }
    for (int i=29;i>=0;i--)
    {
        if (ge0[i]==0)
        {
            ans2[i]=1;
            continue;
        }
        if (ge0[i]>nm) continue;
        ans2[i]=1;
        nm-=ge0[i];
        for (int j=1;j<=n;j++)
        {
            if (!erj[j][i])
            {
                for (int k=0;k<30;k++)
                {
                    if (!erj[j][k])
                    {
                        ge0[k]--;
                        erj[j][k]=1;
                    }
                }
            }
        }
    }
    for (int i=0;i<30;i++)
    {
        if (ans2[i]) ans+=xxx;
        xxx*=2;
    }
    cout<<ans;
    return 0;
}
