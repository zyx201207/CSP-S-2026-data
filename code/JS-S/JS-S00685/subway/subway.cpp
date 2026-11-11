#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500050],w[5050][510],t1[5050][510],t=0,f=-1e9;
bool darkblack[2050][510];
int c,n,m,d,p,k;
int a3(int x,int y,int c,int t6,int t7,int i1,int j2){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k/2;j++)
        {
            if(w[i][j]==x&&darkblack[i][j]==0)
            {
                if(i1!=i&&i1!=0)
                {
                    t7+=t1[i][j];
                    t7+=t1[i1][j2];
                    darkblack[i][j]=1;
                }
                else if(i1==0)
                {
                    t7+=t1[i][j];
                }
                for(int j1=1;j1<=k/2;j1++)
                {
                    t7+=a3(w[i][j1],y,c+1,t6,t7,i,j);
                }
                darkblack[i][j]=0;
            }

            if(w[i][j]==y)
            {
                t7+=t1[i][j];
                t6=min(t7,t6);
                return t6;
            }

        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    {

        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k/2;j++)
        {
            cin>>w[i][j]>>t1[i][j];
        }
    }
        int a1,b1;
        for(int i=1;i<=p;i++)
        {
            cin>>a1>>b1;
            darkblack[a1][b1]=1;
            cout<<a3(a1,b1,1,1e9,0,0,0)<<endl;
            darkblack[a1][b1]=0;
        }

    return 0;
}
