#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int m_m[m];
    for(int i=0;i<n;i++)
    {
        cin>>m_m[i];
    }
    int k[n];
    int map[n][d];
    int t[n][d];
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
        for(int j=0;j<k[i];j++)
        {
            cin>>map[i][j]>>t[n][d];
        }
    }
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        int time=m_m[a]+m_m[b];
        int low=59807027;
        for(int j=0;j<n;j++)

        {
            int pre=0;
            int flag1=0,flag2=0;
            for(int x=0;x<k[j];x++)
            {
                if(map[j][x]==a)
                {
                    pre+=t[j][x];
                    flag1=1;
                }
                if(map[j][x]==b)
                {
                    pre+=t[j][x];
                    flag2=1;
                }
            }
            if(flag1==1&&flag2==1)
            {
                low=min(low,pre);
            }
        }
        cout<<time+low<<endl;
    }
    return 0;
}