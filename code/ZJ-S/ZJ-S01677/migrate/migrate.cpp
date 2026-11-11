#include<bits/stdc++.h>
#define rep(i,l,r) for(int qwp=(r),i=(l);i<=qwp;i++)
#define per(i,r,l) for(int qwp=(l),i=(r);i>=qwp;i--)
#define pb push_back
using namespace std;
typedef long long ll;
constexpr int N=2e6+5;
int n;ll k,a[N];
int pl[N],pr[N];
ll fl[N],fr[N];
vector<int>vl[N],vr[N];
ll sol(int l,int r){
    rep(i,l,r)vl[i]=vr[i]={};
    for(int i=l,j=l;i<=r;i++){
        while(j<r&&a[j+1]-a[i]<=k)j++;
        pl[i]=j,vl[pl[i]].pb(i);
    }
    for(int i=r,j=r;i>=l;i--){
        while(j>l&&a[i]-a[j-1]<=k)j--;
        pr[i]=j,vr[pr[i]].pb(i);
    }
    rep(i,l,r){
        fl[i]=0;
        for(auto j:vl[i])if(j<i){
            fl[i]++;
            if(j>l&&pl[j-1]<i)fl[i]+=fl[j];
        }
    }
    per(i,r,l){
        fr[i]=0;
        for(auto j:vr[i])if(j>i){
            fr[i]++;
            if(j<r&&pr[j+1]>i)fr[i]+=fr[j];
        }
    }
    ll res=0;
    rep(x,l,r-1){
        ll gl=0,gr=0;
        for(auto i:vl[x+1])if(i<x){
            gl++;
            if(i>l&&pl[i-1]<x)gl+=fl[i];
        }
        for(auto i:vr[x])if(i>x+1){
            gr++;
            if(i<r&&pr[i+1]>x+1)gr+=fr[i];
        }
        res+=gl*gr;
    }
    return res;
}
void slv(){
    cin>>n>>k;rep(i,1,n)cin>>a[i];
    ll ans=0;rep(l,1,n){
        int r=l;while(r<n&&a[r+1]-a[r]<=k)r++;
        ans+=sol(l,r),l=r;
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int csi,T;cin>>csi>>T;while(T--)slv();
    return 0;
}
/*
ulimit -v 1048576;ulimit -s 1048576
g++ -O2 -std=c++14 -static migrate.cpp -o %;size %;time ./%
ulimit -s 1048576
g++ -O2 -std=c++14 -fsanitize=address,leak,undefined migrate.cpp -o %;size %;time ./%
*/