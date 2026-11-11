#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[505][505];
int n,m,d,q;
int testlkkk;
int dc[500005];
vector<pair<int,int> > v[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(a,0x3f,sizeof(a));
    cin>>testlkkk>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>dc[i];
    }
    for(int i=1;i<=n;i++){
        int dk;cin>>dk;
        while(dk--){
            int att,ttt;
            cin>>att>>ttt;
            v[att].push_back({i,ttt});
        }
    }
    for(int i=1;i<=m;i++){
        for(int t1=0;t1<v[i].size();t1++){
            for(int t2=t1+1;t2<v[i].size();t2++){
                int uca=v[i][t1].first,vca=v[i][t2].first;
                int le1=v[i][t1].second,le2=v[i][t2].second;
                a[uca][vca]=min(a[uca][vca],le1+le2);
                a[vca][uca]=min(a[vca][uca],le1+le2);
            }
        }
    }
    for(int i=1;i<=n;i++) a[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    while(q--){
        int st,vi;
        cin>>st>>vi;
        int ans=LLONG_MAX;
        for(auto t1:v[st]){
            for(auto t2:v[vi]){
                ans=min(ans,a[t1.first][t2.first]+t1.second+t2.second);
            }
        }
        ans+=dc[st]+dc[vi];
        cout<<ans<<'\n';
    }
    return 0;
}
