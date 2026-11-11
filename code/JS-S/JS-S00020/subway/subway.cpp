#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
const ll V=1e18+10;
ll op[N],dist[510][510];
ll k[510];
ll d[510][N];
ll c,n,dool,m,q;
void floyd(){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>dool>>q;
    for(ll i=0;i<509;i++){
        for(ll j=0;j<509;j++){
            dist[i][j]=V;
            if(i==j) dist[i][j]=0;
        }
    }
    for(ll i=0;i<m;i++){
        cin>>op[i];
    }
    for(ll i=0;i<n;i++){
        cin>>k[i];
        for(ll j=0;j<k[i];j++){
            ll xa,xt;
            cin>>xa>>xt;
            d[i][xa]=xt;
            for(ll k1=0;k1<n;k1++){
                if(d[k1][xa]&&k1!=i){
                    dist[i][k1]=xt+d[k1][xa];
                    dist[k1][i]=xt+d[k1][xa];
                    //cout<<dist[i][k1]<<' '<<i<<' '<<k1;
                    //cout<<endl;
                }
            }
        }
    }
    //ycl
    floyd();
    //floyd
    for(ll i=0;i<q;i++){
        ll u,v;
        cin>>u>>v;

        ll sum=0;
        sum+=dist[u][v];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][u]!=0&&d[j][v]!=0){
                    sum=min(sum,d[i][u]+d[j][v]+dist[i][j]);
                    //cout<<sum<<endl;
                }
            }
        }
        //cout<<op[u-1]<<' '<<op[v-1]<<endl;
        sum=sum+op[v-1]+op[u-1];
        cout<<sum<<endl;
    }
    return 0;
}

/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



0 2 3 20 1
1 2 3
2 1 1 2 2
2 2 2 3 3
1 3


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
