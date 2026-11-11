#include<bits/stdc++.h>
using namespace std;
#define rint register int

int n,k,ans,res,dep[1000005],len[1000005][2],pos[1000005][2];
bool col[15],ok[15];
vector<int>e[1000005];
inline bool check(){
    rint cnt=0;
    for(rint i=1;i<=n;i++){
        ok[i]=0;
        cnt+=col[i];
    }
    if(cnt>k)return 0;
    cnt=0;
    for(rint i=1;i<=n;i++){
        if(col[i]){
            bool flag=1;
            for(auto j:e[i]){
                if(ok[j]){
                    flag=0;
                    break;
                }
            }
            if(flag)cnt++;
            ok[i]=1;
        }
    }
    return cnt<=2;
}
inline int calc(rint cur,rint fa){
    if(col[cur])return 0;
    rint mx=n;
    for(auto y:e[cur]){
        if(y==fa)continue;
        mx=min(mx,calc(y,cur)+1);
    }
    return mx;
}
inline void dfs(rint x){
    if(x==n+1){
        if(check()){
            ans=0;
            for(rint i=1;i<=n;i++)if(!col[i])ans=max(ans,calc(i,0));
            res=min(res,ans);
        }
        return ;
    }
    col[x]=0,dfs(x+1);
    col[x]=1,dfs(x+1);
}
inline void init(rint cur,rint fa){
    dep[cur]=dep[fa]+1;
    len[cur][0]=len[cur][1]=pos[cur][0]=pos[cur][1]=0;
    for(auto y:e[cur]){
        if(y==fa)continue;
        init(y,cur);
        if(len[cur][0]<len[y][0]+1)len[cur][1]=len[cur][0],pos[cur][1]=pos[cur][0],len[cur][0]=len[y][0]+1,pos[cur][0]=y;
        else if(len[cur][1]<len[y][0]+1)len[cur][1]=len[y][0]+1,pos[cur][1]=y;
    }
}
int o;
inline void get(rint cur,rint fa,rint mx,rint tag,rint W){
    res=min(res,max({mx+tag,(dep[cur]-1)/2,len[cur][0],W}));
    for(auto y:e[cur]){
        if(y==fa)continue;
        rint w=len[cur][0],ww=-n;
        if(pos[cur][0]==y)w=len[cur][1];
        if(cur==o)ww=w,w=-n;
        get(y,cur,max(mx,w-tag),tag+1,max(W,ww));
    }
}
inline void solve(){
    cin>>n>>k;
    for(rint i=1;i<=n;i++)e[i].clear();
    for(rint i=1,x,y;i<n;i++){
        cin>>x>>y;
        e[x].push_back(y),e[y].push_back(x);
    }
    if(n<=10){
        res=n,dfs(1);
        cout<<res<<"\n";
        return ;
    }
    res=n;
    for(rint rt=1;rt<=n;rt++){
        o=rt;
        init(rt,0),get(rt,0,-n,0,0);
    }
    cout<<res<<"\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    rint c,t;cin>>c>>t;
    while(t--)solve();
    return 0;
}