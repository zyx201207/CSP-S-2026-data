#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXM = 5e5 + 5,MAXQ = 1e5;
ll c,n,m,d,q;
ll w[MAXM];
ll start[MAXQ],endd[MAXQ];
ll stop[MAXM][500];
ll jiaodian[MAXM];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    ll train[n + 5][m + 5];
    for(int i = 1;i <= m;i++){
        cin>>w[i];
    }
    memset(train,-1,sizeof(train));
    for(int i = 1;i <= n;i++){
        cin>>train[i][0];
        for(int j = 0;j < train[i][0];j++){
            int a,t;
            cin>>a>>t;
            train[i][a] = t;
        }
    }
    for(int i = 1;i <= q;i++){
        cin>>start[i]>>endd[i];
    }
    if(c == 20||c == 21){
        if(n == 1){
            for(int i = 1;i <= q;i++){
                cout<<w[start[i]] + w[endd[i]] + train[1][start[i]] + train[1][endd[i]]<<'\n';
            }
        }else{
            for(int i = 1;i <= q;i++){
                ll ans = 0x7f7f7f7f7f7f7f7f;
                if((train[1][start[i]] != -1&&train[1][endd[i]])||(train[2][start[i]]&&train[2][endd[i]])){
                    if(train[1][start[i]] != -1&&train[1][endd[i]])ans = min(ans,w[start[i]] + w[endd[i]] + train[1][start[i]] + train[1][endd[i]]);
                    else ans = min(ans,w[start[i]] + w[endd[i]] + train[2][start[i]] + train[2][endd[i]]);
                }
                for(int j = 1;j <= m;j++){
                    if(train[1][j] != -1&&train[2][j] != -1){
                        int k = train[1][j] + train[2][j];
                        ans = min(ans,k + w[start[i]] + w[endd[i]]);
                    }
                }
                cout<<ans<<'\n';
            }
        }
    }else if(c ==12||c==13||c==14||c==15){

    }
    return 0;
}