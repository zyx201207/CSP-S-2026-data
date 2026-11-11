#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
struct node {
    int u; int v;
}e[N];
int n,k;
vector <signed> v[N],id[N];
int gravi[3][N];
int dep[N],maxdep[N],maxid[N];
int st,se,maxn,fa[N];
inline void dfs_1(int x,int f,int banid) {
    fa[x]=f;
    dep[x]=dep[f]+1;
    maxdep[x]=dep[x];
    maxid[x]=x;
    for(int i=0;i<v[x].size();++i)
        if(v[x][i]!=f && id[x][i]!=banid) {
            dfs_1(v[x][i],x,banid);
            maxdep[x]=max(maxdep[x],maxdep[v[x][i]]);
            if(maxdep[x]==maxdep[v[x][i]]) maxid[x]=maxid[v[x][i]];
        }
    int stv=dep[x],stid=x,sev=dep[x],seid=x;
    for(int i=0;i<v[x].size();++i)
        if(v[x][i]!=f && id[x][i]!=banid) {
            if(maxdep[v[x][i]]>stv) {
                sev=stv;
                seid=stid;
                stv=maxdep[v[x][i]];
                stid=maxid[v[x][i]];
            }
            else if(maxdep[v[x][i]]>sev) {
                sev=maxdep[v[x][i]];
                seid=maxid[v[x][i]];
            }
        }
    if(stv+sev-dep[x]*2>maxn) {
        maxn=stv+sev-dep[x]*2;
        st=stid,se=seid;
    }
}
inline void calgravi(int x,int banid,int t) {
    maxn=-1;
    dfs_1(x,0,banid);
    vector <int> vvst;
    stack <int> stse;
    while(dep[st]>dep[se]) {
        vvst.push_back(st);
        st=fa[st];
    }
    while(fa[st]!=fa[se]) {
        vvst.push_back(st);
        st=fa[st];
        stse.push(se);
        se=fa[se];
    }
    if(st==se) stse.push(se);
    else {
        stse.push(se);
        se=fa[se];
        stse.push(se);
    }
    while(!stse.empty()) {
        vvst.push_back(stse.top());
        stse.pop();
    }
    // for(int i=0;i<vvst.size();++i)
    //     cout << vvst[i] << " "; cout << "\n";
    int midth=(int)vvst.size()/2;
    gravi[t][banid]=vvst[midth];
}
inline void dfs(int x,int f,int banid) {
    dep[x]=dep[f]+1;
    maxdep[x]=dep[x];
    for(int i=0;i<v[x].size();++i)
        if(v[x][i]!=f && id[x][i]!=banid) {
            dfs(v[x][i],x,banid);
            maxdep[x]=max(maxdep[x],maxdep[v[x][i]]);
        }
}
inline int runans(int lim,int x,int f,int banid) {
    if(maxdep[x]-dep[x]<lim) {
        if(!f) return 1;
        return 0;
    }
    int ret=1;
    for(int i=0;i<v[x].size();++i)
        if(v[x][i]!=f && id[x][i]!=banid) ret+=runans(lim,v[x][i],x,banid);
    return ret;
}
inline int checkval(int x,int banid,int t) {
    dfs(gravi[t][banid],0,banid);
    return runans(x,gravi[t][banid],0,banid);
}
inline bool check(int x) {
    for(int i=1;i<n;++i) {
        if(checkval(x,i,1)+checkval(x,i,2)<=k) return true;
    }
    return false;
}
signed main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T; cin >> c >> T;
    for(int te=1;te<=T;++te) {
        cin >> n >> k;
        for(int i=1;i<=n;++i) {
			v[i].clear();
			id[i].clear();
		}
        for(int i=1;i<n;++i) {
            int x,y; cin >> x >> y;
            v[x].push_back(y); v[y].push_back(x);
            id[x].push_back(i); id[y].push_back(i);
            e[i]=(node){x,y};
        }
        for(int i=1;i<n;++i) {
            calgravi(e[i].u,i,1);
            calgravi(e[i].v,i,2);
            // cout << gravi[1][i] << " " << gravi[2][i] << endl;
        }
        int L=-1,R=n,mid;
        while(L+1<R) {
            mid=(L+R) >> 1;
            if(check(mid)) R=mid;
            else L=mid;
        }
        cout << R << "\n";
    }
    return 0;
}
