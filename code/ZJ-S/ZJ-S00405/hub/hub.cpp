#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5;
int U[N],V[N];
vector<int>g[N];
int dp[N],f[N],n,k,h[N];
void DFS(int u,int pre,int mid){
    h[u]=0;
    dp[u]=1;
    int mx=0;
    for(auto v:g[u]){
        if(v==pre)continue;
        DFS(v,u,mid);
        mx=max(mx,h[v]+1);
        if(h[v]<mid)continue;
        dp[u]+=dp[v];
    }
    h[u]=mx;
}
int Find(int u,int pre,int mid,int Max){
    if(Max>mid)return 1e9;
    int Min=dp[u];
    int maxH=-1e9,smaxH=-1e9;
    for(auto v:g[u]){
        if(v==pre)continue;
        if(h[v]>=maxH){
            smaxH=maxH;
            maxH=h[v];
        }else if (h[v]>=smaxH){
            smaxH=h[v];
        }
    }
    for(auto v:g[u]){
        if(v==pre)continue;
        Min=min(Min, Find(v,u,mid,max(Max+1,(maxH==h[v]?smaxH:maxH)+2)));
    }
    return Min;
}
int check(int mid){
    for(int i=1;i<n;i++){
        DFS(U[i],V[i],mid);
        int A=Find(U[i],V[i],mid,0);
        DFS(V[i],U[i],mid);
        int B=Find(V[i],U[i],mid,0);
        //cout<<U[i]<<" "<<V[i]<<" "<<A<<" "<<B<<" "<<mid<<"\n";
        if(A+B<=k)return 1;
    }
    return 0;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++){
        cin>>U[i]>>V[i];
        int x=U[i],y=V[i];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int L=0,R=n,ans=n;
    while(L<=R){
        int mid=L+R>>1;
        if(check(mid))ans=mid,R=mid-1;
        else L=mid+1;
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)solve();
    return 0;
}