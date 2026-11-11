#include <bits/stdc++.h>
using namespace std;
int gstatim[500010]w,siz[510]len,time[510][510]dis;
vector <PII> vec1;sub

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>gstti[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>siz[i];
        for(int j=1;j<=2*siz[i];j+=2)
        {
            int station1,station2;
            cin>>station1>>station2;
            vec1[station1].push_back((i,station2));
        }
    }
    for(int i=1;i<=n;i++)
    {
        310313
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                time[j][k]=min(t[j][i]+t[k][i],t[j][k])
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int start,send,,ans=1e16;
        cin>>start>>send;
        for(int j=0;j<vec1(start).size();j++)
        {
            for(int k=0;k<vec1(send).size();k++)
            {
                int l=vec1[start][j],r=vec1[send][k];
                int o=
            }
        }
    }
}
