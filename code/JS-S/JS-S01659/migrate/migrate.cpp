#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,inf=0x3f3f3f3f;
ll d;
int L[N],R[N];
vector<int>g[N];
ll a[N],cnt[N],dis[N],idx;
bool vis[N];
struct node{
    int u,w;
    bool operator<(const node PK)const{
        return PK.w<w;
    }
};
void solve(){
    idx++;
    int n,ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i],g[i].clear();
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid,pos=i;
        while(l<=r){
            mid=l+r>>1;
            if(a[i]-a[mid]<=d){
                r=mid-1;
                pos=mid;
            }else l=mid+1;
        }
        L[i]=pos;
        l=i,r=n;
        while(l<=r){
            mid=l+r>>1;
            if(a[mid]-a[i]<=d){
                l=mid+1;
                pos=mid;
            }else r=mid-1;
        }
        R[i]=pos;
        for(int j=L[i];j<=R[i];j++)g[i].push_back(j);
    }
    for(int u=1;u<=n;u++){
        priority_queue<node>q;
        q.push({u,0});
        fill(dis+1,dis+n+1,inf);
        fill(cnt+1,cnt+n+1,0);
        fill(vis+1,vis+n+1,0);
        cnt[u]=1;
        dis[u]=0;
        while(!q.empty()){
            int s=q.top().u;
            q.pop();
            //cout<<s<<endl;
            if(vis[s])continue;
            vis[s]=1;
            for(int v:g[s]){
                if(dis[v]>dis[s]+1){
                    dis[v]=dis[s]+1;
                    q.push({v,dis[v]});
                    cnt[v]=cnt[s];
                }else if(dis[v]==dis[s]+1)cnt[v]+=cnt[s],q.push({v,dis[v]});
            }
        }
        for(int v=1;v<=n;v++){
            if(cnt[v]==2){
                ans++;
                //cout<<u<<" "<<v<<endl;
                //if(idx>=2)cout<<u<<" "<<v<<endl;
            }
        }
    }
    cout<<ans/2<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}
