#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PLL pair<long long,long long>
const int N=5e5+500;
vector<PLL> ve[N],ve1[N];
LL w[N];
bool vis[N];
LL mins=1e14;
void dfs(LL s,LL step,LL e){
    vis[s]=1;
    if(step>=mins)return;
    if(s==e){
        mins=min(mins,step);
    }
    for(auto i:ve[s]){
        for(auto j:ve1[i.first]){
            if(vis[j.first]==1)continue;
            else{
                vis[j.first]=1;
                dfs(j.first,step+i.second+j.second,e);
                vis[j.first]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    LL c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(LL i=1;i<=m;i++){
        cin>>w[i];
    }
    for(LL i=1;i<=n;i++){
        LL k;
        cin>>k;
        for(LL j=1;j<=k;j++){
            LL p,t;
            cin>>p>>t;
            ve[p].push_back({i,t});
            ve1[i].push_back({p,t});
        }
    }
    for(LL i=1;i<=q;i++){
        LL s,e;
        cin>>s>>e;
        mins=1e14;
        dfs(s,0,e);
        cout<<mins+w[s]+w[e]<<endl;
    }
    return 0;
}
