#include<bits/stdc++.h>
#define int long long
//#define DEBUG
using namespace std;
bool M1;
const int N=505,M=5e5+5,Q=1e5+5;
int w[M],k[N];
vector<int> a[N],t[N],ztid[N];
int c,n,m,d,q;
int x[Q],y[Q];
struct Zt{
    int st;
    int li;
    int ti;
}zt[M];
int ztnum=0;
namespace TASK_1_8{
    int dis[N][N];
    void mian(){
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=ztnum;i++){
            dis[i][i]=0;
#ifdef DEBUG
            cerr<<"ZT_"<<i<<':'<<zt[i].st<<' '<<zt[i].li<<' '<<zt[i].ti<<endl;
#endif
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                for(int l=1;l<=k[i];l++){
                    dis[ztid[i][j]][ztid[i][l]]=0;
                }
            }
        }
        for(int i=1;i<=ztnum;i++){
            for(int j=1;j<=ztnum;j++){
                if(zt[i].st==zt[j].st){
                    dis[i][j]=min(dis[i][j],zt[i].ti+zt[j].ti);
                    dis[j][i]=min(dis[j][i],zt[i].ti+zt[j].ti);
                }
            }
        }
        for(int i=1;i<=ztnum;i++){
            for(int j=1;j<=ztnum;j++){
                if(i==j)continue;
                for(int k=1;k<=ztnum;k++){
                    if(i==k||j==k)continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
#ifdef DEBUG
        cerr<<"----------BEGIN_DIS----------"<<endl;
        for(int i=1;i<=ztnum;i++){
            for(int j=1;j<=ztnum;j++){
                cout<<dis[i][j]<<' ';
            }
            cout<<endl;
        }
        cerr<<"------------END_DIS-----------"<<endl;
#endif
        for(int r=1;r<=q;r++){
            int minn=1e15;
            for(int i=1;i<=ztnum;i++){
                if(zt[i].st!=x[r])continue;
                for(int j=1;j<=ztnum;j++){
                    if(zt[j].st!=y[r])continue;
                    minn=min(minn,w[x[r]]+zt[i].ti+w[y[r]]+zt[j].ti+dis[i][j]);
                }
            }
            cout<<minn<<endl;
        }
    }
}
namespace TASK_A{
    const int N1=1005;
    int dis[N1][N1];
    void mian(){
        //cerr<<"---------1--------"<<endl;
        memset(dis,0x3f,sizeof(dis));
        for(int i=1;i<=m;i++){
            dis[i][i]=0;
        }
        //cerr<<"---------2---------"<<endl;
        for(int i=1;i<=n;i++){
            if(k[i]==1)continue;
            //cerr<<"i="<<i<<':'<<k[i]<<' '<<a[i][1]<<' '<<a[i][2]<<endl;
            dis[a[i][1]][a[i][2]]=min(dis[a[i][1]][a[i][2]],t[i][1]+t[i][2]);
            dis[a[i][2]][a[i][1]]=min(dis[a[i][2]][a[i][1]],t[i][1]+t[i][2]);
        }
        //cerr<<"----------3---------"<<endl;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i==j)continue;
                for(int k=1;k<=m;k++){
                    if(i==k||j==k)continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        //cerr<<"----------4----------"<<endl;
        for(int r=1;r<=q;r++){
            cout<<dis[x[r]][y[r]]+w[x[r]]+w[y[r]]<<endl;
        }
    }
}/*
namespace TASK_B{
    const int N=505;
    int dis[N][N];
    vector<int> e[M];
    int tt;
    void mian(){
        for(int i=1;i<=n;i++){
            dis[i][i]=0;
        }
        tt=t[1][1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                e[a[i][j]].push_back(i);
            }
        }
        for(int i=1;i<=ztnum;i++){
            for(int j=0;j<e[zt[i].st];j++){
                dis[zt[i].li][e[zt[i].st][j]]=
                    min(dis[zt[i].li][e[zt[i].st][j]],tt*2);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                for(int k=1;k<=n;k++){
                    if(i==k||j==k)continue;
                    dis[i][j]=min(dis[i][j],dis[i][k],dis[k][j]);
                }
            }
        }
        for(int r=1;r<=q;r++){
            
        }
    }
}*/
bool M2;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].resize(k[i]+2);
        t[i].resize(k[i]+2);
        ztid[i].resize(k[i]+2);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            zt[++ztnum]={a[i][j],i,t[i][j]};
            ztid[i][j]=ztnum;
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
    }
    if(c<=6){
        TASK_1_8::mian();
        return 0;
    }
    if(c<=11){
        TASK_A::mian();
        return 0;
    }
    //cerr<<"Mem:"<<(&M2-&M1)/1048576.0<<endl;
}