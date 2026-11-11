#include<bits/stdc++.h>
using namespace std;
int C,T,n,k,root1,root2,u[100005],v[100005],son[100005],dep[100005],sep[100005],sz[100005],vis[100005],maxn,ans,maxd;
vector<int>a[100005];
void dfs(int nw,int la){
    sz[nw]=1;dep[nw]=1;
    for(int i:a[nw])if(i!=la){
        dfs(i,nw);
        sz[nw]+=sz[i];
        if(dep[nw]<dep[i]+1||dep[nw]==dep[i]+1&&sz[son[nw]]<sz[i])sep[nw]=dep[nw],son[nw]=i;
        else if(sep[nw]<dep[i]+1)sep[nw]=dep[i]+1;
        dep[nw]=max(dep[nw],dep[i]+1);
    }
}
void dfs1(int nw,int la){
    if(sep[nw]>=dep[nw]){
        root1=nw;
        return;
    }
    sep[son[nw]]=sep[nw]+1;
    dfs(son[nw],nw);
}
void dfs2(int nw,int la,int no){
    dep[nw]=dep[la]+1;maxd=max(maxd,dep[nw]);
    for(int i:a[nw])if(i!=la&&i!=no){
        dfs2(i,nw,no);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;ans=n+1;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
            a[u[i]].push_back(v[i]);
            a[v[i]].push_back(u[i]);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=n;j++)dep[j]=sep[j]=sz[j]=vis[j]=0;
            dfs(u[i],v[i]);
            dfs(v[i],u[i]);
            dfs1(u[i],v[i]);root2=root1;
            dfs1(v[i],u[i]);
            dfs2(root2,0,v[i]);
            dfs2(root1,0,u[i]);
            for(int j=1;j<=n;j++)vis[dep[j]]++;
            for(int j=1;j<=n;j++)vis[j]+=vis[j-1];
            while(vis[maxn+1]<=k&&maxn<maxd)maxn++;
            ans=min(ans,maxd-maxn);
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
