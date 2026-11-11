#include<bits/stdc++.h>
using namespace std;
int fa[500005];
int n,m;
int a[500005];
int lin[500005];
vector<int> son[500005];
int c[500005];
int ans[500005];
int dg(int x){
    if(c[x]) return c[x];
    c[x]=1;
    for(auto t:son[x]){
        c[x]+=dg(t);
    }
    return c[x];
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fa[i]=1;
    }
    for(int i=n;i>=1;i--){
        if(lin[a[i]]==0){
            son[i+1].push_back(i);
            lin[a[i]]=i;
        }
        else{
            fa[i]=0;
            son[lin[a[i]]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(c[i]==0) dg(i);
    }
    for(int i=1;i<=n;i++){
        if(fa[i]){
            ans[a[i]]+=c[i];
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
