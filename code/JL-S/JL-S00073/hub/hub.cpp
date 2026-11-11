#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010;
int c,T;
int n,k;
vector<int> edge[N];
int tk;
int need;
bool st[N],ed[N];
bool have(int u,int fa,int dis,int org){
    if((dis>need && st[u]) || (dis+1>need && !st[u])) return true;
    if(st[u]) return false;
    for(auto v:edge[u]){
        if(v==fa) continue;
        if(have(v,u,dis+1,org)) return true;
    }
    return false;
}
bool check(int x){
    need=x;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            for(int kk=1;kk<=n;kk++) st[kk]=ed[kk]=false;
            tk=k-2;
            queue<int> q;
            q.push(i);
            q.push(j);
            st[i]=st[j]=true;
            ed[i]=ed[j]=true;
            while(!q.empty()){
                if(tk<0) break;
                int t=q.front();
                q.pop();
                for(auto v:edge[t]){
                    if(ed[v]) continue;
                    ed[v]=true;
                    if(!have(v,0,0,t)) continue;
                    st[v]=true;
                    tk--;
                    q.push(v);
                }
            }
            //cout<<x<<" "<<i<<" "<<j<<" "<<tk<<endl;
            if(tk>=0) return true;
        }
    return false;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) edge[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int l=0,r=n;
        int ans=0;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
