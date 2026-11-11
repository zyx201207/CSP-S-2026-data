#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define lint long long
#define line inline
#define int long long

namespace OIfast{
	#define endl putchar('\n')

	line lint read(){
		lint x=0;int f=1;char c=getchar();
		while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
		return x*f;
	}

	line void wte(lint x){
		static int sta[40],top=0;
		if(x<0) putchar('-'),x=-x;
		do{sta[++top]=x%10;x/=10;}while(x);
		while(top) putchar(sta[top--]+48);
		return putchar(' '),void();
	}
}using namespace OIfast;

/*
 t3 拼尽全力 24pts 现在 224pts t4 好像 12 pts 最劣暴力
*/

line void _init();

const int N=15,INF=0x3f3f3f3f;
int n,k;

struct edge{
    int to,net;
}e[N];

int head[N],hcnt;

line void add(int u,int v){
    e[++hcnt]={v,head[u]};
    return head[u]=hcnt,void();
}

struct DSU{
    int fa[N],sz[N];

    line void init(int x){
        for(int i=0;i<=x+1;++i) fa[i]=i,sz[i]=0;
        return ;
    }

    line int find(int x){
        return (fa[x]^x)?(fa[x]=find(fa[x])):(x);
    }

    line bool merge(int a,int b){
        a=find(a),b=find(b);
        if(a==b) return false;
        if(sz[a]==sz[b]) ++sz[a];
        if(sz[a]<sz[b]) swap(a,b);
        return fa[b]=a,true;
    }
}ds;

bool imp[N],scc[N];
int ans,rt,dist[N];

line void dfs1(int u,int fa,bool type){
    for(int i=head[u];i;i=e[i].net){
        int v=e[i].to;
        if(v==fa) continue;
        if(type|imp[v]) dist[v]=dist[u];
        else dist[v]=dist[u]+1;
        dfs1(v,u,type|imp[v]);
    }
    return ;
}

line void dfs2(int cur,int cnt){
    if(cnt>k) return ;
    if(cur>n){
//    	cout<<"Come in\n";
        if(cnt<k) return ;
        ds.init(n);
        for(int u=1;u<=n;++u){
            scc[u]=false;
            for(int i=head[u];i;i=e[i].net){
                int v=e[i].to;
                ds.merge(u,v);
            }
        }
        for(int i=1;i<=n;++i){
            scc[ds.find(i)]=true;
        }
        cnt=0;
        for(int i=1;i<=n;++i) if(scc[i]){
            ++cnt;
        }
        if(cnt>2) return ;
        int tmp=0;
        for(rt=1;rt<=n;++rt){
            dist[rt]=0;
            dfs1(rt,0,false);
//            cout<<"Out of the dfs1\n";
            int res=INF;
            for(int i=1;i<=n;++i) if(i^rt){
                res=min(res,dist[i]);
            }
            tmp+=res;
        }
        ans=min(ans,tmp);
//        cout<<"		Coming here\n";
        return ;
    }
//    cout<<"cur = "<<cur<<"\n";
    imp[cur]=false;
    dfs2(cur+1,cnt);
    imp[cur]=true;
    dfs2(cur+1,cnt+1);
    imp[cur]=false;
    return ;
}

line void sol(){
	_init();
    n=read(),k=read();
    for(int i=2,u,v;i<=n;++i){
        u=read(),v=read();
        add(u,v),add(v,u);
    }
//    cout<<"Out of the Building Edges\n";
    ans=INF;
    dfs2(1,0);
//    cout<<"		ans = ";
    wte(ans),endl;
    return ;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
output:
1
2
*/

line void _init(){
	for(int i=1;i<=n;++i){
		head[i]=0;
	}
	return hcnt=0,void();
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
    int c=read(),T=read();
    while(T--) sol();
    return 0;
}