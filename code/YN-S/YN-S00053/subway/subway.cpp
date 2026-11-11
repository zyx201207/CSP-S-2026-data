
#include<iostream>
#include<vector>
#include<bitset>
typedef long long ll;
const int N=555;
const int S=5e5+11;
struct edge{
    int to;
    ll val;
};
struct station{
    int ids;
    ll tme;
};

std::vector<edge>V[N];//地铁线i可以到达的线路
std::vector<station>C[S]; //地铁站i可以换乘的线路
ll w[N],ans;
int c, n, m, d, q ;
std::bitset<N>trm,arr;
ll atme[N];
int st;

void dfs(int now,ll nowans){
    if(nowans>ans)return ;
    if(trm[now]==1){
        ans=std::min(ans,nowans+atme[now]);
        return;
    }

    for(edge i:V[now]){
        if(arr[i.to])continue;

        arr[i.to]=true;
        dfs(i.to,nowans+i.val);
        arr[i.to]=false;
    }
}

void solve(){
    int x,y;
    scanf("%d%d",&x,&y);
    trm.reset();
    ans=1e18;

    for (auto i:C[y])trm[i.ids]=true,atme[i.ids]=i.tme;

    for(auto i:C[x]){
        st=i.ids;
        arr[i.ids]=true;
        dfs(i.ids,i.tme);
        arr[i.ids]=false;
    }

    printf("%lld\n",ans+w[x]+w[y]);
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",w+i);

    for(int i=1,k;i<=n;i++){
        scanf("%d",&k);
        for(int j=1,tmp;j<=k;j++){
            ll chg;
            scanf("%d",&tmp);
            scanf("%lld",&chg);

            for(station x:C[tmp]){
                V[i].push_back(edge{x.ids,chg+x.tme});
                V[x.ids].push_back(edge{i,chg+x.tme});
            }
            C[tmp].push_back({i,chg});
        }
    }

    while(q--)solve();
    return 0;
}