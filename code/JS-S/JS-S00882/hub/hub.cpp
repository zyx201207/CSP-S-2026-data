#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000007
long long C,T,n,k,u,v,fa[MAXN],d[MAXN],cnt,maxn;
set<long long>st;
long long find(long long x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
vector<long long>a[MAXN];
void dfs(long long x,long long up,long long stp){
    if(d[x]>stp)d[x]=stp;
    for(int i=0;i<a[x].size();i++){
        u=a[x][i];
        if(u==up)continue;
        dfs(u,x,stp+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        maxn=MAXN;
        cin>>n>>k;
        for(int i=0;i<n;i++)fa[i]=i,a[i].clear();
        for(int i=1;i<n;i++)cin>>u>>v,u--,v--,a[u].push_back(v),a[v].push_back(u);
        for(int i=0;i<(1<<n);i++){
            st.clear();
            for(int j=0;j<n;j++)d[j]=MAXN;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    for(int o=0;o<a[j].size();o++)fa[find(j)]=find(a[j][o]);
                }
            }
            for(int j=0;j<n;j++){
                if((i>>j)&1)st.insert(i);
            }
            if(st.size()>2)continue;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    dfs(j,-1,0);
                }
            }
            cnt=0;
            for(int j=0;j<n;j++)cnt=max(cnt,d[j]);
            maxn=min(cnt,maxn);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
