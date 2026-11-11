#include<bits/stdc++.h>
using namespace std;
long long m;
int n,acc[500005],syg,jjs;
struct jj{
    long long c,cz;
    int gs,bgs,z;
}ac[500005];
long long jjc[500005];
int jjg[500005];
void xg(){
    int r=jjs,mid,l=0,dn,sy;
    while(l<r){
        mid=(l+r)>>1;
        if(jjc[jjs]-jjc[mid]-jjg[mid]*(ac[jjs].z-ac[mid].z)>m){
            l=mid+1;
        }
        else r=mid;
    }
    dn=(l+r)>>1;
    sy=jjc[jjs]-jjc[dn]-jjg[dn]*(ac[jjs].z-ac[dn].z);
    ac[jjs].bgs=jjg[jjs]-jjg[dn]+(m-sy)/(ac[jjs].z-ac[dn-1].z);
    return ;
}
bool cmp(jj a,jj b){
    return a.bgs>b.bgs;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>acc[i];
    sort(acc+1,acc+1+n);
    syg=acc[1];
    jjs=1;
    ac[1].gs=1;
    for(int i=2;i<=n;i++){
        if(syg!=acc[i]){
            ac[jjs].z=syg;
            ac[jjs].c=acc[i]-syg;
            ac[jjs].cz=ac[jjs].c*ac[jjs].gs;
            if(jjc[jjs]>m)xg();
            else ac[jjs].bgs=jjg[jjs];
            ac[jjs].bgs+=ac[jjs].gs;
            jjs++;
            jjg[jjs]=jjg[jjs-1]+ac[jjs-1].gs;
            jjc[jjs]=jjc[jjs-1]+ac[jjs-1].c*jjg[jjs];
            syg=acc[i];
        }
        ac[jjs].gs++;
    }
    sort(ac+1,ac+1+jjs,cmp);
    cout<<ac[1].bgs;
    return 0;
}
