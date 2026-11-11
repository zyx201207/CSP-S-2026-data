#include<bits/stdc++.h>
using namespace std;
int zn,xn,D;
typedef long long vt;
const vt Infv=1e18;
const int xN=5e5+5,zN=505;
vt vwx[xN];
int nxz[zN];
struct et{
    int to;
    vt v;
};
vector<et>zex[xN],xez[zN];
vt vdiszz[zN][zN];
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
    int x1;
    vt v1;
    for(int z=1;z<=zn;++z){
        cin>>nxz[z];
        for(int i=1;i<=nxz[z];++i){
            cin>>x1>>v1;
            xez[z].push_back({x1,v1});
            zex[x1].push_back({z,v1});
        }
    }
    for(int z1=1;z1<=zn;++z1){
        for(int z2=1;z2<=zn;++z2){
            if(z1==z2){
                vdiszz[z1][z2]=0;
            }
            else{
                vdiszz[z1][z2]=Infv;
            }
        }
    }
    int z1;
    for(int z=1;z<=zn;++z){
        for(et ix:xez[z]){
            x1=ix.to;
            for(et iz:zex[x1]){
                z1=iz.to;
                if(z==z1)continue;
                vdiszz[z][z1]=min(vdiszz[z][z1],ix.v+iz.v);
            }
        }
    }
    for(int z0=1;z0<=zn;++z0){
        for(int z1=1;z1<=zn;++z1){
            if(z0==z1)continue;
            for(int z2=1;z2<=zn;++z2){
                if(z0==z2||z1==z2)continue;
                vdiszz[z1][z2]=min(vdiszz[z1][z2],vdiszz[z1][z0]+vdiszz[z0][z2]);
            }
        }
    }
    int x2;
    int z2;
    vt vans;
    for(;q;--q){
        cin>>x1>>x2;
        vans=Infv;
        for(et i1:zex[x1]){
            z1=i1.to;
            for(et i2:zex[x2]){
                z2=i2.to;
                vans=min(vans,vwx[x1]+i1.v+vdiszz[z1][z2]+i2.v+vwx[x2]);
            }
        }
        cout<<vans<<'\n';
    }
    return 0;
}