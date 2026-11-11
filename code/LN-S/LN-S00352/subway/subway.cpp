#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cost[5005][5005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(cost,-1,sizeof(cost));
    vector<ll>w(m+1);
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        vector<ll>a,t;
        for(int j=1;j<=k;j++){
            ll x,y;
            cin>>x>>y;
            a.push_back(x);
            t.push_back(y);
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i==j)continue;
                if(cost[a[i]][a[j]]==-1||t[i]+t[j]<cost[i][j]){
                    cost[a[i]][a[j]]=t[i]+t[j];
                    //printf("cost[%lld][%lld]=%lld+%lld\n",a[i],a[j],t[i],t[j]);
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(cost[i][j]!=-1&&cost[j][k]!=-1&&cost[i][k]==-1)cost[i][k]=cost[i][j]+cost[j][k];
            }
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(cost[x][y]!=-1)cout<<w[x]+cost[x][y]+w[y]<<'\n';
        else{
            cout<<"!"<<'\n';
        }
    }
    return 0;
}
