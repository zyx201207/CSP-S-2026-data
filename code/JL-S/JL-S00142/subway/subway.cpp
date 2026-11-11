#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10,D=25,Q=5e5+10;
int c,n,m,d,q;
int w[M];
int k[N];
int from[M];
struct Edge{
    int v,w;
};
struct Node{
    int i,d;
    bool operator<(const Node& n)const{
        return d>n.d;
    }
};
struct exNode{
    int i,d,f;
};
vector<Edge>mp[M];
int diss[M],dise[M];
int st[M],sti;
int dj(int s,int e){
    for(int i=1;i<=m+n;i++){
        diss[i]=1e18+10;
    }
    priority_queue<Node>pq;
    sti++;
    pq.push({s,0});
    diss[s]=0;
    while(pq.size()){
        Node t=pq.top();
        pq.pop();
        if(st[t.i]==sti)continue;
        st[t.i]=sti;
        for(auto i:mp[t.i]){
            if(st[i.v]==sti)continue;
            if(t.d+i.w<diss[i.v]){
                diss[i.v]=t.d+i.w;
                pq.push({i.v,diss[i.v]});
            }
        }
    }
    return w[s]+diss[e]+w[e];
}
int sp_B(int s,int e){
    queue <exNode>q;
    int T=mp[s][0].w;
    q.push({s,0,s});
    q.push({e,0,e});
    diss[s]=0;
    diss[e]=0;
    sti++;
    st[s]=sti;
    st[e]=sti;
    from[s]=s;
    from[e]=e;
    int ret;
    bool nfound=1;
    while(q.size()&&nfound){
        exNode t=q.front();
        q.pop();
        for(auto i:mp[t.i]){
            if(st[i.v]==sti){
                if(from[i.v]==t.f)continue;
                ret=diss[i.v]+t.d+1;
                nfound=0;
                break;
            }
            st[i.v]=sti;
            diss[i.v]=t.d+1;
            from[i.v]=t.f;
            q.push({i.v,t.d+1,t.f});
        }
    }
    // ret*=2;
    // ret+=2;
    ret*=T;
    return w[s]+ret+w[e];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    if(c>=7&&c<=11){
        for(int i=1;i<=n;i++){
            cin>>k[i];
            int a1,t1,a2,t2;
            cin>>a1>>t1>>a2>>t2;
            mp[a1].push_back({a2,t1+t2});
            mp[a2].push_back({a1,t1+t2});
        }
    }else{
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                int a,t;
                cin>>a>>t;
                mp[m+i].push_back({a,t});
                mp[a].push_back({m+i,t});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;
        int ans;
        if(c>=12&&c<=19){
            ans=sp_B(s,e);
        }else{
            ans=dj(s,e);
        }
        cout<<ans<<endl;
    }
    return 0;
}