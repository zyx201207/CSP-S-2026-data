#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace YJR{
int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int c,T,n,k,ans;
vector<int> nxt[100005];
bool tag[100005],vis[100005];
queue<pair<int,int>> q;
int bfs(int x){
    for(int i=1;i<=n;i++) vis[i]=0;
    vis[x]=1;
    while(!q.empty()) q.pop();
    q.push({x,0});
    while(!q.empty()){
        int top=q.front().first,cst=q.front().second;
        q.pop();
        if(tag[top]) return cst;
        for(auto it:nxt[top]){
            if(vis[it]) continue;
            vis[it]=1;
            q.push({it,cst+1});
        }
    }
}
int d2f(int x){
    vis[x]=1;
    int res=1;
    while(!q.empty()) q.pop();
    q.push({x,0});
    while(!q.empty()){
        int top=q.front().first;res++;
        q.pop();
        for(auto it:nxt[top]){
            if(vis[it]) continue;
            if(!tag[it]) continue;
            q.push({it,0});
            vis[it]=1;
        }
    }
    return res;
}
bool check(){
    for(int i=1;i<=n;i++) vis[i]=0;
    int tmp=0;
    for(int i=1;i<=n;i++)
        if(tag[i]&&(!vis[i])) d2f(i),tmp++;
    return tmp<=2;
}
void dfs(int x,int cnt){
    if(cnt==k){
        if(!check()) return;
        int res=0;
        for(int i=1;i<=n;i++)
            res=max(res,bfs(i));
        ans=min(ans,res);
        return;
    }
    for(int i=x+1;i<=n;i++){
        tag[i]=1;
        dfs(i,cnt+1);
        tag[i]=0;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),T=read();
    if(c==13||c==14) while(T--){
        n=read(),k=read();
        for(int i=1;i<n;i++)
            read(),read();
        int dt=(n+1)/2/3;

    }
    else while(T--){
        ans=1e18;
        n=read(),k=read();
        for(int i=1;i<=n;i++) nxt[i].clear();
        for(int i=1;i<n;i++){
            int x=read(),y=read();
            nxt[x].push_back(y);
            nxt[y].push_back(x);
        }
        dfs(0,0);
        cout<<ans<<endl;
    }
    // cerr<<clock()*1.0/CLK_TCK;
    return 0;
}
}

signed main(){return YJR::main();}
//g++ hub.cpp -o hub -O2 -std=c++14 -static