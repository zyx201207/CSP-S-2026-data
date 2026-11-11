#include<bits/stdc++.h>
using namespace std;
long long n,dd;
long long ans;
long long a[10005];
__int128_t cntx[10005],minx[10005],vis[10005];
vector<__int128_t>g[10005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    t=1;
    scanf("%lld%lld",&c,&t);
    while(t--){
    ans=0;
    scanf("%lld%lld",&n,&dd);
    __int128_t d=dd;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j)continue;
            __int128_t tmp=0;
            tmp=a[j]-a[i]+tmp;
            if(abs(tmp)<=d){
                g[i].push_back(j);
                g[j].push_back(i);
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++){
        memset(cntx,0,sizeof(cntx));
        memset(minx,-1,sizeof(minx));
        memset(vis,0,sizeof(vis));
        priority_queue<pair<__int128_t,__int128_t>,vector<pair<__int128_t,__int128_t> >,greater<pair<__int128_t,__int128_t> > >p;
        p.push({0,i});
        cntx[i]=1;
        minx[i]=0;
        vis[i]=1;
        while(!p.empty()){
            __int128_t ww=p.top().first;
            __int128_t u=p.top().second;
            p.pop();
            for(auto v:g[u]){
                //if(!vis[v]){
                    //vis[v]=1;
                    if(minx[v]!=-1&&minx[v]<ww+1)continue;
                    cntx[v]+=cntx[u];
                    if(minx[v]==-1)minx[v]=ww+1;
                    p.push({ww+1,v});
                //}
            }
        }
        for(int i=1;i<=n;i++){
            if(cntx[i]==2)ans++;
            //cout<<cntx[i]<<" ";
        }
        //cout<<endl;
    }
    ans>>=1ll;
    printf("%lld\n",ans);
    }
    return 0;
}
