#include<bits/stdc++.h>
using namespace std;
int zn,xn,D;
typedef long long vt;
const vt Infv=1e18;
const int xN=5e5+5,zN=505;
vt vwx[xN];
int nxz[zN];
struct et{
    int t;
    vt v;
};
const int tN=5.01e5+5;
vector<et>tet[tN];
vt vdist[tN];
struct pqt{
    vt vdis;
    int t;
    friend bool operator<(const pqt&a,const pqt&b){
        return a.vdis>b.vdis;
    }
};
priority_queue<pqt>pq;
bitset<tN>vist;
int tn;
vt dijk(const int&tS,const int&tT){
    for(int t=1;t<=tn;++t){
        vdist[t]=Infv;
        vist[t]=0;
    }
    while(pq.size())pq.pop();
    vdist[tS]=0;
    pq.push({vdist[tS],tS});
    int tx,ty;
    while(pq.size()){
        tx=pq.top().t;
        pq.pop();
        if(vist[tx]){
            continue;
        }
        vist[tx]=1;
        if(tx==tT){
            /* NOTE */
            return vdist[tx];
        }
        for(et i:tet[tx]){
            ty=i.t;
            if(vdist[tx]+i.v<vdist[ty]){
                vdist[ty]=vdist[tx]+i.v;
                pq.push({vdist[ty],ty});
            }
        }
    }
    return Infv;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Tc;
    int q;
    cin>>Tc>>zn>>xn>>D>>q;
    for(int x=1;x<=xn;++x){
        cin>>vwx[x];
    }
    int x1,x2;
    vt v1;
    for(int z=1;z<=zn;++z){
        cin>>nxz[z];
        for(int i=1;i<=nxz[z];++i){
            cin>>x1>>v1;
            tet[xn+z].push_back({x1,v1});
            tet[x1].push_back({xn+z,v1});
        }
    }
    tn=xn+zn;
    vt vans;
    for(;q;--q){
        cin>>x1>>x2;
        vans=dijk(x1,x2)+vwx[x1]+vwx[x2];
        cout<<min(vans,Infv)<<'\n';
    }
    return 0;
}