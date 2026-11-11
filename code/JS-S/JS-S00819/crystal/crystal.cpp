/*
g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall
1. pushup & pushdown
2. int overflow? ll space? __int128?
3. guess bravely
4. constant factor VS. log
5. don't be afarid of countings.
6. is the sample large enough?

*/
#include<bits/stdc++.h>
using namespace std;
#define y0 xcxakioi
#define y1 fcyakioi
#define x0 XCXAKIOI
#define x1 FCYAKIOI
namespace File{
    void Redirect(string s){
        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        string Istr=s+".in",Ostr=s+".out";
        freopen(Istr.c_str(),"r",stdin),freopen(Ostr.c_str(),"w",stdout);
    }
}
namespace Rngdle{
    int gen(int L,int R){
        while(1){
            int v=rand()%(R-L+1)+L,ok=1;
            for(int i=2;i*i<=v;i++){
                if(!(v%i)){
                    ok=0;
                    break;
                }
            }
            if(ok)return v;
        }
    }
}
namespace Treap{
    const int Trp=100005;
    int ls[Trp],rs[Trp],pri[Trp],val[Trp],siz[Trp],cnt[Trp],tot;
    void clear(){
        memset(ls,0,sizeof(int)*(tot+1));
        memset(rs,0,sizeof(int)*(tot+1));
        memset(pri,0,sizeof(int)*(tot+1));
        memset(val,0,sizeof(int)*(tot+1));
        memset(siz,0,sizeof(int)*(tot+1));
        memset(cnt,0,sizeof(int)*(tot+1));
        tot=0;
    }
    int ext(int x){
        tot++;
        pri[tot]=rand(),val[tot]=x,siz[tot]=cnt[tot]=1;
        return tot;
    }
    void down(int u){

    }
    void up(int u){
        siz[u]=siz[ls[u]]+siz[rs[u]]+cnt[u];
    }
    void split(int u,int lim,int &x,int &y){
        if(!u){
            x=y=0;
            return;
        }
        down(u);
        if(val[u]<=lim)split(rs[u],lim,rs[u],y),up(u);
        else split(ls[u],lim,x,ls[u]),up(u);
    }
    int merge(int x,int y){
        if(!x||!y)return x|y;
        down(x),down(y);
        if(pri[x]>pri[y]){
            rs[x]=merge(rs[x],y),up(x);
            return x;
        }
        ls[y]=merge(x,ls[y]),up(y);
        return y;
    }
}
namespace Megt{
    const int Segn=100005,Segs=Segn<<6;

}
namespace Segt{

}
#define int long long
const int N=500005;
int pre[N],a[N],n,m,ans;
main(){
    srand(time(0)),File::Redirect("crystal");
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
        int L=1,R=i;
        while(L^R){
            int mid=(L+R)/2,len=i-mid+1,modi=a[i]*len-(pre[i]-pre[mid-1]);
            if(modi>m)L=mid+1;
            else R=mid;
        }
        ans=max(ans,i-L+1);
    }
    cout<<ans;
}
/*
14:40 T1
*/