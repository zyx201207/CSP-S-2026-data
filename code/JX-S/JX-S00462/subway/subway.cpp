#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
ll sta[500005];
ll rai[505][500005];
vector<ll> s_r[500005];
ll r_r[505][505];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>sta[i];
    memset(rai,0x3f,sizeof rai);
    memset(r_r,0x3f,sizeof r_r);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            ll r,w;
            cin>>r>>w;
            rai[i][r]=w;
            s_r[r].push_back(i);
        }
    }
    for(int i=1;i<=n;i++) r_r[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int u=0;u<s_r[i].size();u++){
            for(int v=0;v<s_r[i].size();v++){
                if(u==v) continue;
                r_r[s_r[i][u]][s_r[i][v]]=min(r_r[s_r[i][u]][s_r[i][v]],rai[s_r[i][u]][i]+rai[s_r[i][v]][i]);
                r_r[s_r[i][v]][s_r[i][u]]=min(r_r[s_r[i][v]][s_r[i][u]],rai[s_r[i][u]][i]+rai[s_r[i][v]][i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(r_r[i][j]>r_r[i][k]+r_r[j][k]) r_r[i][j]=r_r[i][k]+r_r[j][k];
            }
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        ll ans=1e18+5;
        for(int i=0;i<s_r[s].size();i++){
            for(int j=0;j<s_r[t].size();j++){
                ans=min(ans,sta[s]+rai[s_r[s][i]][s]+r_r[s_r[s][i]][s_r[t][j]]+rai[s_r[t][j]][t]+sta[t]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}