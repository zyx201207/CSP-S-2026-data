#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e6+510,MAXM=5e6+10;
typedef long long ll;
int hed[MAXN],nxt[MAXM],to[MAXM],cntg;
ll w[MAXM];
void edge(int u,int v,int wi){
    cntg++;
    nxt[cntg]=hed[u];
    to[cntg]=v;
    hed[u]=cntg;
    w[cntg]=wi;
}
int c,n,m,d,q;
int getpt(int x){
    if(x>m)return x-m;
    else return x+m;
}

struct pt{
    ll dis;
    int i;
    bool operator <(const pt& other)const{
        return dis>other.dis;
    }
};

ll dis[MAXN];
bool vis[MAXN];
priority_queue<pt> st;
void dj(int be){
    //cout<<"te";
    for(int i=1;i<=m*2+n;i++){
        dis[i]=LLONG_MAX;
        vis[i]=false;
    }
    while(!st.empty())st.pop();

   // cout<<st.empty()<<" "<<"te";
    pt x,cur;
    dis[be]=0;
    x.dis=0;x.i=be;
    st.push(x);
    while(!st.empty()){
        //cout<<st.size()<<endl;
        //cout<<"te";
        cur=st.top();
        st.pop();
        //cout<<cur.i<<endl;
        if(vis[cur.i]){
            cout<<"te";
            continue;
        }
        vis[cur.i]=true;
        //cout<<cur.i<<endl;
        //cout<<"te";
        for(int i=hed[cur.i];i!=0;i=nxt[i]){
            //cout<<"te";
            int v=to[i];
            if(vis[v])continue;
            if(dis[v]>dis[cur.i]+w[i]){
                dis[v]=dis[cur.i]+w[i];
                x.i=v;
                x.dis=dis[v];
                st.push(x);
            }
        }
    }
}

struct qy{
    int be;
    int en;
    int i;
}query[100010];
ll ans[100010];
int now=-1;
bool cmp(qy x,qy y){
    return min(x.be,x.en)<min(y.be,y.en);
}
int main(){
    
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);



    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    ll wi;
    for(int i=1;i<=m;i++){
        cin>>wi;
        edge(i,getpt(i),wi);
        edge(getpt(i),i,wi);
    }
    int k,a,t;
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            edge(m*2+i,getpt(a),t);
            edge(getpt(a),2*m+i,t);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>query[i].be>>query[i].en;
        query[i].i=i;
    }

    sort(query+1,query+1+q,cmp);

    for(int i=1;i<=q;i++){
        int x=min(query[i].en,query[i].be);
        if(now!=x){
            dj(x);
            //cout<<"te";
            now=x;
        }
        ans[query[i].i]=dis[query[i].en+query[i].be-x];
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}