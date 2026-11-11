#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q,p,x,y,qx,qy,cnt,tmp,ans,qh[505][2],stat[500005],subs[505][505];
struct node{
    ll v,t;
};
bool cmp(node a,node b){
    return a.v<b.v;
}
vector<node>a[505];
ll binsearch(ll k,ll sz,ll x){
    ll lft=0,rgt=sz-1,mid;
    while(lft<=rgt){
        mid=(lft+rgt)/2;
        if(a[k][mid].v==x)return mid;
        if(a[k][mid].v>x)rgt=mid-1;
        if(a[k][mid].v<x)lft=mid+1;
    }
    return -1ll;
}
void init(){
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<a[i].size();j++){
            for(ll k=i+1;k<=n;k++){
                if((tmp=binsearch(k,a[k].size(),a[i][j].v))>-1){
                    subs[i][k]=subs[k][i]=min(subs[k][i],a[i][j].t+a[k][tmp].t);
                }
            }
        }
    }
    for(ll i=1;i<=n;i++){
        subs[i][i]=0;
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                subs[i][j]=min(subs[i][j],subs[i][k]+subs[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(subs,0x3f,sizeof subs);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(ll i=1;i<=m;i++){
        scanf("%lld",&stat[i]);
    }
    for(ll i=1;i<=n;i++){
        scanf("%lld",&p);
        for(ll j=1;j<=p;j++){
            scanf("%lld%lld",&x,&y);
            a[i].push_back({x,y});
        }
        sort(a[i].begin(),a[i].end(),cmp);
    }
    init();
    for(ll i=1;i<=q;i++){
        scanf("%lld%lld",&qx,&qy);
        cnt=0;ans=0x3f3f3f3f;
        for(ll j=1;j<=n;j++){
            if((tmp=binsearch(j,a[j].size(),qx))>-1)cnt++,qh[cnt][0]=j,qh[cnt][1]=tmp;
        }
        for(ll j=1;j<=n;j++){
            if((tmp=binsearch(j,a[j].size(),qy))>-1){
                for(ll k=1;k<=cnt;k++){
                    ans=min(ans,stat[qx]+stat[qy]+a[qh[k][0]][qh[k][1]].t+a[j][tmp].t+subs[qh[k][0]][j]);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
