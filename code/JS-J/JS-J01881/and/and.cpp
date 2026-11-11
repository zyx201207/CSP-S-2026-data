#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,lc[N*31],rc[N*31],sz[N*31],tot=1;
inline void insert(int v){
    sz[1]++;
    int u=1;
    for(int i=29;i>=0;i--){
        if(v>>i&1){
            if(!rc[u])rc[u]=++tot;
            u=rc[u];
        }else{
            if(!lc[u])lc[u]=++tot;
            u=lc[u];
        }sz[u]++;
    }
}vector<int>dfs(int u){
    if(!lc[u]&&!rc[u]){
        vector<int>temp;
        for(int i=1;i<=sz[u];i++)temp.push_back(0);
        return temp;
    }if(rc[u]&&sz[rc[u]]>=m){
        auto tmp=dfs(rc[u]);
        for(int &i:tmp)i=i>>1|1<<29;
        return tmp;
    }vector<int>l,r;
    if(lc[u]){
        l=dfs(lc[u]);
        for(int &i:l)i>>=1;
    }if(rc[u]){
        r=dfs(rc[u]);
        for(int &i:r)i=i>>1|1<<29;
    }if(!lc[u])return r;
    if(!rc[u])return l;
    vector<int>temp;
    size_t sz=min((size_t)m,l.size()+r.size());
    for(size_t i=0;i<sz;i++){
        int tmp=0;
        if(i<l.size())tmp=max(tmp,l[i]);
        if(i<r.size())tmp=max(tmp,r[i]);
        for(int j=min(i-1,l.size()-1);j>=0;j--)tmp=max(tmp,l[j]&r[i-j-1]);
        temp.push_back(tmp);
    }return temp;
}int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int v;
        scanf("%d",&v);
        insert(v);
    }printf("%d",dfs(1)[m-1]);
    return 0;
}