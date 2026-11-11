#include<bits/stdc++.h>
using namespace std;
const long long bignum=1e18;
long long c,n,m,d,q,w[500010],xr,yr;
long long k[510],a[500010],t[500010],sum[510];
long long di[500010],isk[510],ism[500010],b[500010];
vector<pair<long long,long long>>e[500010];
void dij(){
    for(int i=1;i<=n;i++)isk[i]=0;
    for(int i=1;i<=m;i++)ism[i]=0,di[i]=bignum;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
    q.push({0,xr});
    di[xr]=0;
    while(!q.empty()){
        pair<long long,long long>now=q.top();
        q.pop();
        long long u=now.second;
        if(u==yr)return;
        if(ism[u])continue;
        ism[u]=1;
        for(int i=1;i<=b[u];i++){
            long long vk1=e[u][i].first,vk2=e[u][i].second;
            long long wk=t[sum[vk1-1]+vk2];
            if(isk[vk1])continue;
            isk[vk1]=1;
            for(int j=1;j<=k[vk1];j++){
                long long wk2=wk+t[sum[vk1-1]+j],v=a[sum[vk1-1]+j];
                if(wk2+di[u]>di[v])continue;
                di[v]=di[u]+wk2;
                q.push({di[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        e[i].resize(d+1);
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[sum[i-1]+j]>>t[sum[i-1]+j];
            e[a[sum[i-1]+j]][++b[a[sum[i-1]+j]]]={i,j};
        }
        sum[i]=sum[i-1]+k[i];
    }
    for(int i=1;i<=q;i++){
        cin>>xr>>yr;
        dij();
        di[yr]+=w[xr]+w[yr];
        cout<<di[yr]<<endl;
    }
    return 0;
}
