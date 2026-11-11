#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500010];
ll dis[510][510];
vector< pair<int,int> > stainf[500010];
void solve(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            stainf[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        ll cnt=stainf[i].size();
        for(int j=0;j<cnt;j++){
            for(int k=j+1;k<cnt;k++){
                ll u=stainf[i][j].first;ll v=stainf[i][k].first;
                ll t=stainf[i][j].second+stainf[i][k].second;
                dis[u][v]=min(dis[u][v],t);
                dis[v][u]=min(dis[v][u],t);
                //cout<<u<<'\t'<<v<<'\t'<<dis[u][v]<<endl;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        ll x,y;
        cin>>x>>y;
        ll ans=1e18;
        ll xcnt=stainf[x].size();
        ll ycnt=stainf[y].size();
        for(int j=0;j<xcnt;j++){
            for(int k=0;k<ycnt;k++){
                ll u=stainf[x][j].first;ll v=stainf[y][k].first;
                ll t=stainf[x][j].second+stainf[y][k].second;
                ans=min(ans,dis[u][v]+t);
            }
        }
        //cout<<x<<"    "<<y<<endl;
        cout<<ans+w[x]+w[y]<<endl;
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
这个题意真的很长……

发现在地铁内部是可以零步行任意移动的，主要是换乘的步行

那是不是可以对每个地铁建点跑Floyd？

怎么处理每个站可以换乘的情况？

k最多是5e5的话，就假设每个站出现了m个换乘地铁

那么应该就是k/p*(p^2)=kp

那问题不大了，本来算了发现是个2e8的东西十分恐惧来着

那直接挂在每个站上暴力遍历所有组合就可以了

Visual Studio Code is really slow......Dev C++ is much quicker......
*/
