#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5;
ll m,n,c,d,q,x,y;
ll w[505];
ll a[505][505];
vector<pair<int,ll>> b[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
        cin>>w[i];
    for(ll i=1;i<=n;i++){
        ll k,x,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x>>t;
            for(auto p:b[x]){
                ll tmp=p.second+t;
                if(a[x][p.first]==0||a[x][p.first]>tmp){
                    a[x][p.first]=tmp;
                    a[p.first][x]=tmp;
                }
            }
            b[x].push_back({i,t});
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(a[i][k]==0) continue;
            for(int j=i+1;j<=n;j++){
                if(a[k][j]==0) continue;
                int t=a[i][k]+a[k][j];
                if(a[i][j]!=0&&t>=a[i][j]) continue;
                a[i][j]=t;
                a[j][i]=t;
            }
        }
    }
    for(int i=0;i<q;i++){
        cin>>x>>y;
        ll ans=LONG_LONG_MAX,t=w[x]+w[y];
        for(auto i:b[x]){
            for(auto j:b[y]){
                ll tmp=t+a[i.first][j.first]+i.second+j.second;
                ans=min(ans,tmp);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
