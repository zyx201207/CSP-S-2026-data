#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long c,n,m,d,q,w[N],s,minn=N;
struct stu{
    long long a,t;
};
struct st{
    long long x,y;
};
stu sub[N][N];
st road[N];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>sub[i][0].a;
        for(int j=1;j<=sub[i][0].a;j++){
            cin>>sub[i][j].a>>sub[i][j].t;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>road[i].x>>road[i].y;
    }
    for(int i=1;i<=q;i++){
        s=w[road[i].x]+w[road[i].y];

    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=n;j++){
            for(int m=1;m<=sub[j][0].a;m++){
                for(int n=m+1;n<=sub[j][0].a;n++){
                    if((road[i].x==sub[j][m].a && road[i].y==sub[j][n].a)||(road[i].y==sub[j][m].a && road[i].x==sub[j][n].a)){
                        long long mint=0;
                        for(int l=m;l<=n;l++){
                            mint+=sub[j][l].t;
                        }
                        minn=min(minn,mint);
                    }
                }

            }
        }
        cout<<minn<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


