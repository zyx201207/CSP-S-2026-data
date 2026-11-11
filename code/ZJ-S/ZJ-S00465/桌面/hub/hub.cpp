#include <bits/stdc++.h>
#define ll long long 
#define sc scanf 
#define pr printf
#define v1 first 
#define v2 second 
#define IINF 0x3f3f3f3f 
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N=1e6+5;
vector<pair<int,int>> v[N];
int b[N],fa[N],sz[N],d[N];
bool bl[N];
int find(int x){
    return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
set<pair<int,int>> st;
void merge(int x,int y,bool mk) {
    x=find(x),y=find(y);
    if(x==y)return;
    if(mk)st.erase({sz[x],x});
    if(mk)st.erase({sz[y],y});
    if(sz[y]<sz[x])swap(x,y);
    fa[x]=y;sz[y]+=sz[x];
    if(mk)st.insert({sz[y],y});
}
int mxd[N];
void dfs1(int k,int f){
    mxd[k]=1;
    for(auto y:v[k]){
        if(y.v1==f)continue;
        dfs1(y.v1,k);
        mxd[k]=max(mxd[y.v1]+1,mxd[k]);
    }
}
void dfs2(int k,int f,int mm){
    int mmx=mm;b[k]=1;
    if(!f)mmx=1,b[k]=0;
    int mx=-IINF,mxid=0,smx=-IINF;
    for(auto z:v[k]){
        int y=z.v1;
        if(y==f)continue;
        if(mxd[y]>mx)smx=mx,mx=mxd[y],mxid=y;
        else if(mxd[y]>smx)smx=mxd[y];
        if(mxd[y]+1>mmx)b[k]=mmx,mmx=mxd[y]+1;
        else if(mxd[y]+1>b[k])b[k]=mxd[y]+1;
    }
    for(auto y:v[k]){
        if(y.v1==f)continue;
        if(y.v1==mxid)dfs2(y.v1,k,max(mm+1,smx+2));
        else dfs2(y.v1,k,max(mm+1,mx+2));
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int _,t;
    sc("%d%d",&_,&t);
    while(t--){
        int n,m;sc("%d%d",&n,&m);
        for(int i=1; i <= n; i++)v[i].clear();
        for(int i=1,x,y; i < n; i++){
            sc("%d%d",&x,&y);
            v[x].push_back({y,i});v[y].push_back({x,i});
        }
        for(int i=1; i <= n; i++)b[i]=-1;
        dfs1(1,0);
        dfs2(1,0,1);
        // for(int i=0; i <= 10; i++)cout << cnt[i]<<" ";cout << endl;
        vector<int> vv;int pos=0;
        for(int i=1; i <= n; i++)vv.push_back(i),d[i]=v[i].size(),fa[i]=i,sz[i]=1,bl[i]=1;
        for(int i=1; i <= n; i++)
        sort(vv.begin(),vv.end(),[=](int x,int y){return b[x]<b[y];});
        int cnt=n;
        for(int i=1; i <= n; i++){
            if(d[i]==2){
                int cur=0;
                for(auto y:v[i]){
                    if(cur)merge(cur,y.v2,0);
                    cur=y.v2;
                }
            }
        }
        for(int i=1; i < n; i++){
            if(fa[i]==i)st.insert({sz[i],i});
        }
        int ans=IINF;
        for(int i=0; i <= n; i++){
            // cout << i << " "<< st.size()<<endl;
            if(pos==vv.size())break;
            while(pos<vv.size()&&b[vv[pos]]<=i){
                int x=vv[pos];
                bl[x]=0;
                for(auto y:v[x]){
                    if(!bl[y.v1])continue;
                    --d[y.v1];
                    st.erase({sz[find(y.v2)],find(y.v2)});
                    --sz[find(y.v2)];
                    st.insert({sz[find(y.v2)],find(y.v2)});
                    if(d[y.v1]==2){
                        int cur=0;
                        for(auto z:v[x]){
                            if(bl[z.v1]){
                                if(cur)merge(cur,z.v2,1);
                                cur=z.v2;
                            }
                        }
                    }
                }
                --cnt;++pos;
            }   
            int res=max(min(st.rbegin()->v1-1,i*2-1),0);
            // cout <<i <<" "<< res <<" "<< cnt << endl;
            if(cnt-res<=m){
                ans=i;break;
            }
        }
        pr("%d\n",ans);
    }
    return 0;
}