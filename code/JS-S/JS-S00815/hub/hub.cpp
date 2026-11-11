#include<bits/stdc++.h>
#define N 2000005
using namespace std;
int c,t,n,m;
vector<int> gv[N];
int dep[N];
int zj[N];
int tot;
void dfs1(int now,int fa){
    dep[now]=dep[fa]+1;
    for(auto nx:gv[now]) if(nx!=fa){
        dfs1(nx,now);
    }
}
bool dfs2(int now,int tar,int fa){
    if(now==tar){
        zj[++tot]=now;
        return 1;
    }
    for(auto nx:gv[now]){
        if(nx==fa) continue;
        if(dfs2(nx,tar,now)){
            zj[++tot]=now;
            return 1;
        }
    }
    return 0;
}
int L,R;
void dfs3(int now,int fa){
    dep[now]=min(dep[now],dep[fa]+1);
    for(auto nx:gv[now]) if(nx!=fa) dfs3(nx,now);
}
int toL[N],toR[N];
bool vis[N];
void dfs4(int now,int fa,int *dep){
    dep[now]=dep[fa]+1;
    for(auto nx:gv[now]) if(nx!=fa) dfs4(nx,now,dep);
}
bool check(int mid){
    if(mid+1 >= tot-mid) return 1;
    if(mid+2==tot-mid) return 1;
    if(m==2){
        for(int i=1;i<=n;i++) dep[i]=1e9;
        dep[zj[mid+1]]=dep[zj[tot-mid]]=0;
        dfs3(zj[mid+1],0);
        dfs3(zj[tot-mid],0);
        for(int i=1;i<=n;i++) if(dep[i]>mid) return 0;
        return 1;
    }
    if(c==13 or c==14){
        int len=tot-mid-mid-1-1-m+2;
        return (len+1)/2<=mid;
    }
    // for(int i=1;i<=n;i++) toL[i]=toR[i]=vis[i]=0;
    // dfs4(zj[mid+1],zj[mid],toL);
    // dfs4(zj[tot-mid],zj[tot-mid+1],toR);
    // if(c==13 or c==14){
    //     return toR[mid+1+]-m<=mid;
    // }
    return 1;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
cin>>c>>t;
while(t--){
    cin>>n>>m;
    for(int i=1;i<=n;i++) gv[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        gv[u].push_back(v);
        gv[v].push_back(u);
    }
    for(int i=1;i<=n;i++) dep[i]=0;
    dfs1(1,0);
    R=1;
    int maxd=0;
    for(int i=1;i<=n;i++) if(maxd<dep[i]) maxd=dep[i],R=i;
    for(int i=1;i<=n;i++) dep[i]=0;
    dfs1(R,0);
    L=1;
    maxd=0;
    for(int i=1;i<=n;i++) if(maxd<dep[i]) maxd=dep[i],L=i;
    tot=0;
    dfs2(R,L,0);
    int l=0,r=tot-1,ans=r;
    // cout<<"zj"<<endl;
    // for(int i=1;i<=tot;i++) cout<<zj[i]<<' ';cout<<endl;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    cout<<ans<<'\n';
}
}
/*
Oct31==Dec25?
not fun but 1h
yi wan ge ren yao ak le ...
*/

/*
#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
vector<string> def,res,pre;
string gen(string s){
    if(mp.count(s)){
        return mp[s];
    }
    string ans="";
    for(int i=1;i<=10;i++){
        ans+=rand()%26+'A';
    }
    def.push_back("#define "+ans+" "+s);
    return mp[s]=ans;
}
signed main(){
    // mp["using"]="using";
    // mp["namespace"]="namespace";
    // mp["std"]="std";
    srand(time(0));
    string s;
    while(getline(cin,s)){
        if(s[0]=='#'){
            pre.push_back(s);
            continue;
        }
        string ans="",cur="";
        for(auto nx:s){
            if((nx>='a' and nx<='z') or (nx>='A' and nx<='Z') or (nx>='0' and nx<='9') or nx=='_'){
                cur+=nx;
            }
            else{
                if(cur!=""){
                    ans+=gen(cur);
                    cur="";
                }
                ans+=nx;
            }
        }
        res.push_back(ans);
    }
    for(auto nx:pre) cout<<nx<<endl;
    for(auto nx:def) cout<<nx<<endl;
    for(auto nx:res) cout<<nx<<endl;
}

*/