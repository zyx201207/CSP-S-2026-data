#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
vector<int>E[N],di;
vector<int>L[N],R[N];
int n,k,u,v,f1[N],vis[N],m1[N],m2[N],siz,rt,tmp,od[N],h[N],nxt[N],mn[N],dfn[N],vi[N],ct[N];
void dfs1(int u,int fa=0){
    //cout<<u<<" df"<<E[u].size()<<endl;
    for(auto &&v:E[u]){
        if(v==fa)continue;
        dfs1(v,u);
        if(f1[v]>=m1[u])m2[u]=m1[u],m1[u]=f1[v];
        else m2[u]=max(m2[u],f1[v]);
    } f1[u]=m1[u]+1;
    if(m1[u]+m2[u]+1>siz)siz=m1[u]+m2[u]+1,rt=u;
}
void dfs2(int u,int fa=0){
    od[u]=1; di.pb(u);
    for(auto &&v:E[u])
    if(v!=fa&&f1[v]==m1[u]){
        dfs2(v,u);
        break;
    }
}
void dfs3(int u,int fa=0){
    for(auto &&v:E[u])if(v!=fa)dfs3(v,u),h[u]=max(h[u],h[v]);
    h[u]++,nxt[u]=fa;
}
void init(){
    siz=rt=tmp= 0;  di.clear();
    for(int i=1;i<=n;i++)f1[i]=vis[i]=m1[i]=m2[i]=od[i]=h[i]=nxt[i]=dfn[i]= 0;

    dfs1(1); di.pb(rt); od[rt]=1;
    for(auto &&u:E[rt])if(f1[u]==m1[rt]){
        tmp=u,dfs2(u,rt); reverse(di.begin(),di.end());
        break;
    }
    for(auto &&u:E[rt])if(u!=tmp&&f1[u]==m2[rt]){
        dfs2(u,rt); break;
    }
    for(int i=0;i<siz;i++)
        dfn[di[i]]=i;
    for(int i=1;i<=n;i++)if(od[i]){
        for(auto &&u:E[i])if(!od[u]){
            dfs3(u,i);
        }
    }
    //cout<<siz<<" "<<rt<<endl; for(auto &&i:di)cout<<i<<" "; puts("");
}
bool check(int x){
    int cnt=0;
    for(int i=1;i<=n;i++)vi[i]=mn[i]=ct[i]= 0;
    for(int i=0;i<siz;i++)
        L[i].clear(),R[i].clear();
    vi[di[x  ]  ]=1; cnt++;
    vi[di[siz-x-1] ]=1;
    if(x!=siz-x-1)cnt++;
    for(int i=1,j;i<=n;i++){
        if(h[i]==x){
            j=nxt[i];
            if(vi[j])continue;
            //if(x==1)cout<<i<<"sdfassadf---------------df"<<endl;
            while(!vi[j]){
                vi[j]=1;cnt++;
                if(od[j])break;  j=nxt[j];
            }
        }
        j=nxt[i];
        if(od[j])
            mn[dfn[j]]=max(mn[dfn[j]],h[i]);
    }
    vector<int>t;
    for(int i=0;i<siz;i++)
        if(vi[di[i] ])t.push_back(i);
    int len=t.size();
    //if(x==1){
    //    cout<<len<<endl; for(auto &&i:t)cout<<di[i]<<" "; puts("");
    //}
    cnt=cnt+(t[len-1]-t[0]+1)-len;
    //if(x==1)cout<<cnt<<"dsfasdf\n";


    if(cnt<=k)return 1;
    cnt=cnt-k;
    vector<pii>S;
    //if(x==1)cout<<cnt<<endl;
    for(int i=0;i<len-1;i++){
        int l=t[i],r=t[i+1],flag=0;
        int sl=r-l-1;
        for(int j=l+1;j<r;j++){
            int RR=x-mn[j];
            if(l<j-RR&&j+RR<r){
                flag=1;
                L[j-RR].pb(j);
                R[j+RR].pb(j);
            }
        }
        if(!flag){
            if(r-l-1>=cnt)return 1;
            continue;
        }
        S.clear();
        S.pb({0,0});
        for(int j=r-1;j>l;j--){
            for(auto &&k:R[j])
            S.pb({r-j,k});
        }
        int tt=S.size()-1;
        for(int j=l+1;j<r;j++){
            for(auto &&k:L[j])ct[k]=1;
            while(ct[S[tt].se ])tt--;
            if(sl-(j-l)-S[tt].fi>=cnt)return 1;
        }
    }
    return 0;
}
void solve(){
    n=read(),k=read();
    for(int i=1;i<=n;i++)E[i].clear();
    for(int i=1;i<n;i++)u=read(),v=read(),E[u].push_back(v),E[v].push_back(u);
    //cout<<"asdfasdf"<<E[1].size()<<endl;
    init();
    int l=1,r=siz/2,mid,ans=0;
    while(l<=r){
        mid=l+r>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }printf("%d\n",ans);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t; t=read(),t=read();
    while(t--)solve();
    return 0;
}
