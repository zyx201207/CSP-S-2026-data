#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4010;
int n,k,a[N],fa[N];
vector<int> G[N];
int findf(int x){
    if(fa[x]==x)return x;
    else return fa[x]=findf(fa[x]);
}
bool check(int x){
    for(int i=0;i<k;i++){
        for(int j=0;j<g[a[i]].size();j++){
            if((x>>j)&1==1){
                int fax=findf(i),fay=findf(g[a[i]][j]);
                fa[fax]=fay;
            }
        }
    }
    set<int> shu;
    for(int i=0;i<k;i++){
        shu.insert(findf(a[i]));
    }
    if(shu.size()<=2){
        return 1;
    }else return 0;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout<<n/3<<endl;
    return 0;
    for(int i=0;i<(1ll<<n);i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1==1)cnt++;
        }
        if(cnt!=k)continue;
        for(int i=0;i<=n;i++)fa[i]=i;
        int an=0;
        for(int i=0;j<n;j++){
            if((i>>j)&1==1){
                a[an++]=j;
            }
        }
        if(check(i)){
            solve(i);
        }
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,T;cin>>c>>T;
    while(T--){
        solve();
    }
}
