#include<bits/stdc++.h>
using namespace std;
//priority_queue
//operator
const long long N=510,M=5e5+10;
long long c,n,m,d,q;
long long w[M];
struct ST{
    long long to,num;
};
struct PQ{
    long long to,num;
    bool operator< (const PQ& ppqq) const{
        if(num!=ppqq.num) return num>ppqq.num;
       return to<ppqq.to;
    }
};
map<long long,long long > iszhan[N];
long long visit[N];
vector<ST> zhan[M];
vector<ST> xian[N];
long long xtx[N][N];
long long f[N][N];
vector <ST> xtxx[N];
int  main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        for(long long j=1;j<=k;j++){
            long long z,t;
            cin>>z>>t;
            iszhan[i][z]=j-1;
            zhan[z].push_back({i,t});
            xian[i].push_back({z,t});
        }
    }
/*
    for(long long  i=1;i<=n;i++){

        for(long long  j=i;j<=n;j++){
            long long num=0x3f3f3f3f;
            if(i==j){
                xtx[i][j]=0;continue;
            }
            for(auto k:xian[i]){
                auto it=iszhan[j].find(k.to);
                if(it==iszhan[j].end()){
                    continue;
                }
                num=min(num,k.num+xian[j][iszhan[j][k.to]].num);
            }
            xtx[i][j]=xtx[j][i]=num;
        }
    }
*/

    memset(xtx,0x3f3f3f3f,sizeof xtx);
    for(long long i=1;i<=m;i++){
        for(long long j=0;j<zhan[i].size();j++){
            xtx[zhan[i][j].to][zhan[i][j].to]=0;
            for(long long k=j+1;k<zhan[i].size();k++){
                long long timee=zhan[i][j].num+zhan[i][k].num;
                if(xtx[zhan[i][j].to][zhan[i][k].to]>timee){
                    xtx[zhan[i][j].to][zhan[i][k].to]=timee;
                    xtx[zhan[i][k].to][zhan[i][j].to]=timee;
                }
            }
        }
    }

    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            xtxx[i].push_back({j,xtx[i][j]});
            xtxx[j].push_back({i,xtx[i][j]});
            //cout<<i<<"->"<<j<<":"<<xtx[i][j]<<'\n';
        }
    }
   // cout<<endl<<endl;
    //fload
    memset(f,0x3f3f3f3f,sizeof f);
    for(long long i=1;i<=n;i++){
        f[i][i]=0;
        for(long long j=i+1;j<=n;j++){
            for(auto next:xtxx[j]){
                f[j][i]=min(f[j][i],f[i][next.to]+next.num);
                f[i][j]=min(f[i][j],f[i][next.to]+next.num);

            }
        }
    }

    while(q--){
        long long x,y;
        cin>>x>>y;
        long long ans=0x3f3f3f3f;

        for(auto i:zhan[x]){
            for(auto j:zhan[y]){
                ans=min(ans,f[i.to][j.to]+i.num+j.num);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
