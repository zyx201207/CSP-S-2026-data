#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000010;
int c,t;
int n,k;

inline ll read(){
    ll s=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*f;
}

struct node{
    ll to,nxt;
}e[2*maxn];
ll head[maxn],ind=1;
void add_edge(ll u,ll v){
    e[++ind].to=v;
    e[ind].nxt=head[u];
    head[u]=ind;
}

int d,ce;
void dfs(int u,int from,int st){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==from) continue;
        if(st+1>d){
            ce=v;
            d=st+1;
        }
        dfs(v,u,st+1);
    }
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    c=read(),t=read();
    while(t--){
        n=read(),k=read();
        int m=(n-1)/2;
        ans=(m+1)/8-(k+1)/2+1;
        printf("%lld\n",ans);
    }
    return 0;
}
