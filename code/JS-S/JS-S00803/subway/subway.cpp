// So why O(n (\sum k)log(\sum k) + nq) TLE on machine???
// Can anyone help me?? Just mail me in Luogu(QiuOutlook). Xuan Guan before 2026/11/10.

#include<bits/stdc++.h>
using ll=long long;
// ll read(){
//     ll n=0,ch=1;
//     char c;
//     while(c=getchar(),!isdigit(c)){
//         if(c=='-'){
//             ch=-1;
//         }
//     }

//     n=c-'0';
//     while(c=getchar(),isdigit(c)){
//         n=n*10+c-'0';
//     }
//     return n*ch;
// }

int main(){
    // void* start_memory=new int;
    // std::clock_t time=clock();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c,n,m,d,q;
    std::cin>>c>>n>>m>>d>>q;
    std::vector<ll> w(m+1);
    for(int i=1;i<=m;++i){
        std::cin>>w[i];
    }

    auto id=[&](int k){
        return k+m;
    };

    struct edge{
        int v;
        ll w;
    };
    std::vector<std::vector<edge> > G(n+m+1);
    for(int i=1;i<=n;++i){
        int k;
        std::cin>>k;
        for(int j=0;j<k;++j){
            int v;
            ll w;
            std::cin>>v>>w;
            G[id(i)].push_back({v,w});
            G[v].push_back({id(i),w});
        }
    }

    // std::cerr<<"input getted\n";

    // for(int i=1;i<=n+m;++i){
    //     std::cout<<i<<":\n";
    //     for(auto j:G[i]){
    //         std::cout<<j.v<<"("<<j.w<<") ";
    //     }
    //     std::cout<<'\n';
    // }

    std::vector<std::vector<ll> > dist(n+1,std::vector<ll>(n+m+1,std::numeric_limits<ll>::max()/3));
    struct info{
        int u;
        ll w;
    };
    struct cmp{
        bool operator()(info a,info b){
            return a.w>b.w;
        }
    };

    std::priority_queue<info,std::vector<info>,cmp> Q;
    for(int s=1;s<=n;++s){
        Q.push({id(s),0});
        dist[s][id(s)]=0;
        while(!Q.empty()){
            info now=Q.top();
            Q.pop();

            if(dist[s][now.u]!=now.w){
                continue;
            }

            // if(now.u>=id(1)&&now.u<id(s)){
            //     for(int i=1;i<=id(n);++i){
            //         if(dist[s][i]>now.w+dist[now.u-m][i]){
            //             dist[s][i]=now.w+dist[now.u-m][i];
            //             Q.push({i,now.w+dist[now.u-m][i]});
            //         }
            //     }
            //     continue;
            // }

            for(auto e:G[now.u]){
                int v=e.v;
                ll w=e.w;
                if(dist[s][v]>now.w+w){
                    dist[s][v]=now.w+w;
                    Q.push({v,now.w+w});
                }
            }
        }
        // std::cerr<<(clock()-time)*1.0/CLOCKS_PER_SEC<<"s\n";
    }

    // std::cerr<<"dist computed\n";

    // for(int i=1;i<=n;++i){
    //     std::cout<<"subway "<<i<<": ";
    //     for(int j=1;j<=n+m;++j){
    //         std::cout<<dist[i][j]<<' ';
    //     }
    //     std::cout<<"\n";
    // }

    for(int i=0;i<q;++i){
        int l,r;
        std::cin>>l>>r;
        ll ans=std::numeric_limits<ll>::max();

        for(int k=1;k<=n;++k){
            ans=std::min(ans,dist[k][l]+dist[k][r]);
        }
        std::printf("%lld\n",ans+w[l]+w[r]);
        // if(i%10==0){
        //     std::cerr<<(clock()-time)*1.0/CLOCKS_PER_SEC<<"s\n";
        // }
    }

    // void* end_memory=new int;
    // std::cerr<<((int*)end_memory-(int*)start_memory)/4.0/1024/1024<<" MB\n";
    // std::cerr<<(clock()-time)*1.0/CLOCKS_PER_SEC<<"s";

    return 0;
}