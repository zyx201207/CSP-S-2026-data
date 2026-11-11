#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k,no[4],yes[4],w[500005]={},mapp[1002][1002]={};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(mapp,0x3f3f3f,sizeof(mapp));
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        if(k==1) cin>>no[1]>>yes[1];
        if(k==2){
            cin>>no[2]>>yes[2];
            cin>>no[3]>>yes[3];
            mapp[no[2]][no[3]]=yes[2]+yes[3];
        }
    }
    for(int kkk=1;kkk<=4;kkk++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int l=1;l<=m;l++)
                {
                    mapp[i][j]=min(mapp[i][j],mapp[i][l]+mapp[l][j]);
                }
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<mapp[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
