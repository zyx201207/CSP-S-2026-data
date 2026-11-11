#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=500005;
ll c,n,m,d,q;
ll w[M];
vector<ll> lx[N];
vector<ll> ti[N];
ll gr[10005][10005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(gr,0x3f,sizeof(gr));
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll v,t;
            cin>>v>>t;
            lx[i].push_back(v);
            ti[i].push_back(t);
        }
        for(int u=0;u<k;u++){
            for(int v=u+1;v<k;v++){
                if(!gr[lx[i][u]][lx[i][v]] || gr[lx[i][u]][lx[i][v]]>ti[i][u]+ti[i][v]){
                    gr[lx[i][u]][lx[i][v]]=gr[lx[i][v]][lx[i][u]]=ti[i][u]+ti[i][v];
                }
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                gr[i][j]=min(gr[i][j],gr[i][k]+gr[k][j]);
            }
        }
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<(gr[l][r]+w[l]+w[r])<<'\n';
    }
    return 0;
}
