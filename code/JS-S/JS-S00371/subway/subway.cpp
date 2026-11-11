#include <iostream>
#include<queue>
using namespace std;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    unsigned int c, n, m, d, q,w[500010],a[510][30],t[510][30],k[510];//input
    unsigned int zhan[500010][30]={0},inr[500010][510];
    cin>>c>>n>>m>>d>>q;
    for(unsigned int i=0;i<m;i++)
    {
        cin>>w[i];
    }
    for(unsigned int i=0;i<n;i++)
    {
        cin>>k[i];
        for(unsigned int j=0;j<k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            zhan[a[i][j]][++zhan[a[i][j]][0]]=i;
            inr[a[i][j]][i]=zhan[a[i][j]][0];
        }
    }
    for(unsigned int tmpo=0;tmpo<q;tmpo++)
    {
        unsigned int time[500010]={0};
        for(unsigned int i=0;i<m;i++)
        {
            time[i]--;
        }
        int x,y;
        cin>>x>>y;
        x--,y--;
        time[x]=w[x];
        queue<int> qu;
        qu.push(x);
        while(!qu.empty())
        {
            int dangqian=qu.front();
            qu.pop();
            for(unsigned int i=1;i<=zhan[dangqian][0];i++)
            {
                for(unsigned int j=0;j<k[zhan[dangqian][i]];j++)
                {
                    if(t[zhan[dangqian][i]][i]+t[a[zhan[dangqian][i]][j]][inr[a[zhan[dangqian][i]][j]][zhan[dangqian][i]]]+time[dangqian]<time[a[zhan[dangqian][i]][j]])
                    {
                        time[a[zhan[dangqian][i]][j]]=t[zhan[dangqian][i]][i]+t[a[zhan[dangqian][i]][j]][inr[a[zhan[dangqian][i]][j]][zhan[dangqian][i]]]+time[dangqian];
                        qu.push(a[zhan[dangqian][i]][j]);
                    }
                }
            }
        }
        cout<<w[y]+time[y]<<'\n';
    }
    return 0;
}
