#include<bits/stdc++.h>
using ll=long long;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c,t;
    std::cin>>c>>t;
    for(int i=0;i<t;++i){
        int n;
        ll d;
        std::cin>>n>>d;

        std::vector<ll> x(n+1);
        for(int i=1;i<=n;++i){
            std::cin>>x[i];
        }

        // For readers from Luogu:
        // Want to know why I deleted the code? I want to, t00.
        // So how T2/T3? mail me in Luogu: QiuOutlook
        //
        // std::vector<int> l(n+1),r(n+1);
        // for(int i=1;i<=n;++i){
        //     // l[i]=std::upper_bound(x.begin()+1,x.end(),(__int128)x[i]-d-1)-x.begin();
        //     r[i]=std::lower_bound(x.begin()+1,x.end(),(__int128)x[i]+d)-x.begin();
        // }


        // std::vector<std::vector<ll> > dist(n+1,std::vector<ll>(n+1,std::numeric_limits<ll>::max()/2)),road(n+1,std::vector<ll>(n+1,0));
        // // std::vector<ll> sum;
        // struct info{
        //     int u;
        //     ll w;
        // };
        // std::deque<info> Q;
        // // std::unordered_map<ll,ll> m;

        // // ll ans=0;
        // for(int i=1;i<=n;++i){
        // //     if(fa[i]==i){
        // //         dist.resize(sz[i]);
        // //         road.resize(sz[i]);
        // //         sum.resize(sz[i]);
        // //         for(int j=0;j<sz[i];++j){
        // //             dist[j]=-1;
        // //             road[j]=0;
        // //             sum[j]=0;
        // //         }

        //         Q.push_back({i,0});
        //         dist[i][i]=0;
        //         road[i][i]=1;
        //         while(!Q.empty()){
        //             info now=Q.front();
        //             Q.pop_front();

        //             if(dist[i][now.u]!=now.w){
        //                 continue;
        //             }
        //             for(int v=now.u+1;v<=r[now.u];++v){
        //                 // if(now.u==v){
        //                 //     continue;
        //                 // }
        //                 if(dist[i][v]>now.w+1){
        //                     dist[i][v]=now.w+1;
        //                     road[i][v]=0;
        //                     Q.push_back({v,dist[i][v]});
        //                 }
        //                 if(dist[i][v]==now.w+1){
        //                     ++road[i][v];
        //                 }
        //             }
        //         }

        // //         sum[0]=dist[0];
        // //         for(int i=1;i<sz[i];++i){
        // //             sum[i]=sum[i-1]+dist[i];
        // //         }
        // //     }

        // //     ans+=m[road[i]/2]

        // }

        std::vector<std::vector<ll> > dist(n+1,std::vector<ll>(n+1,std::numeric_limits<ll>::max()/2)),road(n+1,std::vector<ll>(n+1,0));
        struct info{
            int u;
            ll w;
        };
        std::deque<info> Q;

        for(int i=1;i<=n;++i){
            Q.push_back({i,0});
            dist[i][i]=0;
            road[i][i]=1;
            while(!Q.empty()){
                info now=Q.front();
                Q.pop_front();

                if(dist[i][now.u]!=now.w){
                    continue;
                }
                for(int v=now.u+1;v<=n;++v){
                    if(x[v]-x[now.u]>d){
                        break;
                    }
                    if(dist[i][v]>now.w+1){
                        dist[i][v]=now.w+1;
                        road[i][v]=0;
                        Q.push_back({v,dist[i][v]});
                    }
                    if(dist[i][v]==now.w+1){
                        road[i][v]+=road[i][now.u];
                    }
                }
            }
        }

        long long ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                // std::cerr<<i<<' '<<j<<'\n';
                if(road[i][j]==2){
                    ++ans;
                }
            }
        }
        std::cout<<ans<<'\n';
    }
    return 0;
}
