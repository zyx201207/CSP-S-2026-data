#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int> gn[509];
unordered_map<int,int> gm[500009];
int n,m,c,d;
int w[500009];
int hm[500009],hn[509];
int sdat[509][509];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld",&c,&n,&m,&d);
    int q;
    scanf("%lld",&q);
    for(int i = 1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i = 1;i<=n;i++){
        int k;
        scanf("%lld",&k);
        for(int j = 1;j<=k;j++){
            int a,t;
            scanf("%lld %lld",&a,&t);
            gm[a][i] = t;
            gn[i][a] = t;
        }
    }
    // for(int k = 1;k<=m;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<i;j++){
                //i- > j
                memset(hn,0x7f,sizeof(hn));
                memset(hm,0x7f,sizeof(hm));
                queue<pair<int,bool>> pq;
                hn[i] = 0;
                pq.push(make_pair(i,0)); //0 subway 1 point
                while(pq.size()){
                    pair<int,bool> x = pq.front();
                    pq.pop();
                    int t = x.first;
                    int tp = x.second;
                    if(tp){
                        for(auto ttt:gm[t]){
                            int it = ttt.first,tt = ttt.second;
                            if(!hn[it]||hn[it] >= hm[t] + tt) hn[it] = hm[t] + tt, pq.push(make_pair(it,0));
                        }
                    }else{
                        for(auto ttt:gn[t]){
                            int it = ttt.first,tt = ttt.second;
                            if(!hm[it]||hm[it] >= hn[t] + tt) hm[it] = hn[t] + tt, pq.push(make_pair(it,1));
                        }
                    }
                }
                sdat[i][j] = hn[j];
                sdat[j][i] = hn[j];
                // if(i != j && sdat[i][j] > gn[i][k] + gm[k][j]) sdat[i][j] = gn[i][k] + gm[k][j];
            }
            // printf("\n");
        }

    // }
    for(int i = 1;i<=q;i++){
        int x,y;
        scanf("%lld %lld",&x,&y);
        int ans = 0x7f7f7f7f7f7f7f7f;
        for(auto ttt:gm[x]){
            int it = ttt.first,tt = ttt.second;
            for(auto tttt:gm[y]){
                int itt = tttt.first, ttttt = tttt.second;
                ans = min(ans,sdat[it][itt]+tt+ttttt);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
}
