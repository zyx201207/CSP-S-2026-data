#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int L=5e5+10;
int c,n,m,d,que,w[L],ch,a[L],t[L],st,ed,ans[L];
bool vis[L];
vector<pii> ve[L];
priority_queue<pii,vector<pii>,greater<pii> > q;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>que;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int xx=1;xx<=n;++xx){
        cin>>ch;
        for(int i=1;i<=ch;++i) cin>>a[i]>>t[i];
        for(int i=1;i<=ch;++i){
            for(int j=i+1;j<=ch;++j){
                ve[a[i]].push_back({a[j],t[i]+t[j]});
                ve[a[j]].push_back({a[i],t[i]+t[j]});
            }
        }
    }
    while(que--){
        cin>>st>>ed;
        for(int i=1;i<=m;++i){
            ans[i]=INT_MAX;
            vis[i]=0;
        }
        ans[st]=0;
        while(!q.empty()) q.pop();
        q.push({0,st});
        while(!q.empty()){
            int f1=q.top().first,f2=q.top().second;
            q.pop();
            if(f2==ed){
                cout<<f1+w[st]+w[ed]<<endl;
                break;
            }
            if(vis[f2]) continue ;
            vis[f2]=1;
            for(auto y:ve[f2]){
                if(ans[y.first]>ans[f2]+y.second){
                    ans[y.first]=ans[f2]+y.second;
                    q.push({ans[y.first],y.first});
                }
            }
        }
    }
    return 0;
}
//Oct31==Dec25?
