#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int kmaxn=505,kmaxm=5e5+10,Ma=1e16;
int idT,n,m,D,Q,an[kmaxn][kmaxn],w[kmaxm];
vector<pair<int,int> >P[kmaxm];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>idT>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            an[i][j]=Ma;
        }
    }
    for(int i=1;i<=n;i++){
        an[i][i]=0;
        int sz;cin>>sz;
        while(sz--){
            int x,y;cin>>x>>y;
            P[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(pair<int,int>j:P[i]){
            for(pair<int,int>k:P[i]){
                an[j.first][k.first]=min(an[j.first][k.first],j.second+k.second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                an[i][j]=min(an[i][j],an[i][k]+an[k][j]);
            }
        }
    }
    while(Q--){
        int x,y;cin>>x>>y;
        int ans=Ma;
        for(pair<int,int>i:P[x]){
            for(pair<int,int>j:P[y]){
                ans=min(ans,an[i.first][j.first]+i.second+j.second);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}