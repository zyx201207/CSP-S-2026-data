#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,inf=1e8;
bool p1;
int C,T,n,k,siz[N],f[N],dep_sec[N],dep_mx[N],dep[N],ans,mid,mx,sz[4][N],zzz=0,fl;
bool p2;
struct node{
    int l,r;
}a[N];
vector<int>v[N],id;
vector<node>pt;
void clear(){
    pt.clear();
    for(int i=1;i<=n;i++)
        v[i].clear();
    for(int i=1;i<=n;i++)   
        f[i]=dep[i]=dep_mx[i]=dep_sec[i]=0;
    ans=inf;
    return;
}
void dfs(int x,int fa){
    dep_mx[x]=dep_sec[x]=0;
    for(int i:v[x]){
        if(i==fa)
            continue;
        dep[i]=dep[x]+1;
        dfs(i,x);
        if(dep_mx[i]+1>dep_mx[x]){
            dep_sec[x]=dep_mx[x];
            dep_mx[x]=dep_mx[i]+1;
        }
        else
            dep_sec[x]=max(dep_sec[x],dep_mx[i]+1);
    }
    return;
}
void find_mid_all(int x,int fa,int val){
    int cf=abs(dep_mx[x]-max(val,dep_sec[x]));
    if(cf==1&&val>dep_mx[x]){
        pt.push_back(node{fa,x});
        mid=x;
        return;
    }
    else if(cf==0){
        mid=x;
        if(val==dep_mx[x]){
            pt.push_back(node{fa,x});
            for(int i:v[x]){
                if(i==fa) continue;
                if(dep_mx[x]==dep_mx[i]+1){
                    pt.push_back(node{x,i});
                    // return;
                }
            }
        }
        else{
            for(int i:v[x]){
                if(i==fa) continue;
                if(dep_mx[x]==dep_mx[i]+1)
                    pt.push_back(node{x,i});
                // if(pt.size()>=2) 
                //     return;
            }
        }
    }
    for(int i:v[x]){
        if(dep_mx[i]+1==dep_mx[x])
            find_mid_all(i,x,max(val,dep_sec[x])+1);
    }
    return;
}
void find_mid(int x,int fa,int val){
    zzz=max(zzz,dep_mx[x]+max(val,dep_sec[x]));
    int cf=abs(dep_mx[x]-max(val,dep_sec[x]));
    if(cf==0){
        mid=x;
        id.push_back(x);
        return;
    }
    else if(cf==1){
        mid=x;
        id.push_back(x);
    }
    for(int i:v[x])
        if(dep_mx[i]+1==dep_mx[x])
            find_mid(i,x,max(val,dep_sec[x])+1);
    return;
}
void solve(int x,int fa){
    mx=max(mx,dep[x]);
    dep_mx[x]=0;
    siz[x]=1;
    for(int i:v[x]){
        if(i==fa) continue;
        dep[i]=dep[x]+1;
        solve(i,x);
        dep_mx[x]=max(dep_mx[x],dep_mx[i]+1);
        siz[x]+=siz[i];
    }
    if(fl==0)
        sz[1][dep_mx[x]]++,sz[0][dep_mx[x]]++;
    else
        sz[2][dep_mx[x]]++,sz[0][dep_mx[x]]++;
    return;
}
void solvef(int x,int fa){
    mx=max(mx,dep[x]);
    dep_mx[x]=0;
    siz[x]=1;
    for(int i:v[x]){
        if(i==fa) continue;
        dep[i]=dep[x]+1;
        solvef(i,x);
        dep_mx[x]=max(dep_mx[x],dep_mx[i]+1);
        siz[x]+=siz[i];
    }
    if(fl==0)
        sz[2][dep_mx[x]]++,sz[3][dep_mx[x]]++;
    else
        sz[1][dep_mx[x]]++,sz[3][dep_mx[x]]++;
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>C>>T;
    while(T--){
        clear();
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>a[i].l>>a[i].r;
            v[a[i].l].push_back(a[i].r);
            v[a[i].r].push_back(a[i].l);
        }
        // if(T!=2)
            // continue;
        dfs(1,1);
        find_mid_all(1,1,0);
        // cout<<mid<<' ';
        // cout<<dep_mx[mid]<<' '<<dep_sec[mid]<<'\n';
        if(C<=10&&n<=4000){
            for(int i=1;i<n;i++){
                pt.push_back(node{a[i].l,a[i].r});
            }
        }
        for(node i:pt){
            int sec_mx=0;
            // id.clear()
            // cout<<"case:"<<i.l<<' '<<i.r<<' '<<k<<'\n';
            for(int j=0;j<=n;j++){
                v[j].clear();
                sz[0][j]=sz[1][j]=sz[2][j]=sz[3][j]=0;
            }
            for(int j=1;j<n;j++){
                if(a[j].l==i.l&&a[j].r==i.r)
                    continue;
                if(a[j].l==i.r&&a[j].r==i.l)
                    continue;
                v[a[j].l].push_back(a[j].r);
                v[a[j].r].push_back(a[j].l);
            }
            dep[i.l]=dep[i.r]=0;
            zzz=0;
            id.clear();
            dfs(i.l,i.l);
            find_mid(i.l,i.l,0);
            fl=1;
            dep[mid]=0;
            // if(id.size()>1)
                solvef(id[0],id[0]);
            dep[mid]=0;
            solve(mid,mid);
            sec_mx=zzz;
            // cout<<id.size()<<' ';
            // cout<<dep_mx[mid]<<' ';
            zzz=0;
            id.clear();
            dfs(i.r,i.r);
            find_mid(i.r,i.r,0);
            dep[mid]=0;
            fl=0;
            // if(id.size()>1)
                solvef(id[0],id[0]);
            dep[mid]=0;
            solve(mid,mid);
            sec_mx=min(sec_mx,zzz);
            for(int idx=0;idx<4;idx++){
                int tot=0;
                for(int p=mx;p>=0;p--){
                    tot+=sz[idx][p];
                    if(tot>k||tot==k&&p<=sec_mx&&p>(sec_mx+1)/2){
                        // cout<<idx<<' '<<p<<' '<<tot<<'\n';
                        break;
                    }
                    ans=min(ans,p);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}   