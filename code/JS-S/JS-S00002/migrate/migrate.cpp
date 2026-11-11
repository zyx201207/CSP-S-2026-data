#include <bits/stdc++.h>
using namespace std;
const int N=2000005;
long long c,t,n,d,x[N],l,dis[N],ans;
vector<long long> v[N];
map<pair<long long,long long>,long long> cnt;
void dijkstra(long long x){
    for (int i=1;i<=n;++i){
        dis[i]=1e9;
    }
    dis[x]=0;
    for (int i=x;i<=n;++i){
        for (int j:v[i]){
            if (dis[j]>dis[i]+1){
                dis[j]=dis[i]+1;
                cnt[{x,j}]=1;
            }
            else if (dis[j]==dis[i]+1){
                cnt[{x,j}]+=cnt[{x,i}];
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for (int i=1;i<=n;++i) v[i].clear();
        for (int i=1;i<=n;++i){
            cin>>x[i];
            for (int j=1;j<i;++j){
                if (x[i]-x[j]<=d){
                    v[j].push_back(i);
                }
            }
        }
        for (int i=1;i<n;++i){
            cnt.clear();
            dijkstra(i);
            for (int j=i+1;j<=n;++j){
                if (cnt[{i,j}]==2){
                    ans++;
                    //cout<<i<<" "<<j<<"\n";
                }
                //cout<<cnt[{i,j}]<<" ";
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
