#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
using ll=long long;
int fa[505];
int mj[505];
int xz[505];
int xj[505];
struct ed{
    int u,v;
    ll w;
};
struct o{
    int q=-1,z=-1;
}a[505];
vector<ed> edg;
vector<ed> use;
bool cmp(ed x,ed y){
    return x.w<y.w;
}
bool cmp2(ed x,ed y){
    return x.u<y.u;
}
int find(int x){
    if(x==fa[x]) return x;
    else return find(fa[x]);
}
bool unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return false;
    else return true;
}
int qi,zh;
int mi(int x){
    for(int i=a[x].q;i<=a[x].z;i++){
        if(use[i].v==zh){
            return use[i].w;
        }
        if(a[use[i].v].q==-1){
            continue;
        }else if(mi(a[use[i].v].q)==-1){
            continue;
        }else{
            cout<<x<<" ";
            return use[i].w+mi(a[use[i].v].q);
        }
    }
    return -1;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>mj[i];
    while(n--){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>xz[i]>>xj[i];
        }
        for(int i=1;i<k;i++){
            for(int j=i+1;j<=k;j++){
                edg.push_back({xz[i],xz[j],xj[i]+xj[j]});
            }
        }
    }
    sort(edg.begin(),edg.end(),cmp);
    for(int i=1;i<=m;i++) fa[i]=i;
    int cnt=0;
    for(auto &e:edg){
        int u=e.u,v=e.v;
        if(unite(u,v)){
            use.push_back(e);
            fa[v]=u;
            cnt++;
        }
        if(cnt==m-1) break;
    }
    sort(use.begin(),use.end(),cmp2);
    for(int i=0;i<m-1;i++){
        if(a[use[i].u].q==-1){
            a[use[i].u].q=i;
        }
        if(a[use[i+1].u].q==-1 && i+1<m-1){
            a[use[i].u].z=i;
        }else if(i==m-2){
            a[use[i].u].z=i;
        }
    }
    while(q--){
        cin>>qi>>zh;
        cout<<mi(qi)+mj[qi]+mj[zh]<<endl;
    }
    return 0;
}
