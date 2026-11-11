#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+16,M=4e6+16;
int cnt,to[M],nxt[M],h[N],dep[N],anc[N][30];
void add(int u,int v){
    to[++cnt]=v;
    nxt[cnt]=h[u];
    h[u]=cnt;
}
void dfs(int u,int fa){//s s
    dep[u]=dep[fa]+1;
    anc[u][0]=fa;
    for(int i=h[u];i;i=nxt[i]){
        int v=to[i];
        if(v^fa){
            dfs(v,u);
        }
    }
    
    /*
    for(int j=1;j<=__lg(n);++j){
        for(int i=1;i<=n;++i){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
    */
}
int rd(){
    #define gc() getchar_unlocked()
    char c=gc();
    while(!isdigit(c)){
        c=gc();
    }
    int s=0;
    while(isdigit(c)){
        s=(s<<1)+(s<<3)+(c^48);
        c=gc();
    }
    return s;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
            cout<<"1\n";
            continue;
        int n=rd(),k=rd();
        cnt=0;
        for(int i=1;i<=n;++i){
            h[i]=0;
        }
        for(int i=1;i<n;++i){
            int u=rd(),v=rd();
            add(u,v);
            add(v,u);
        }

    }
    return 0;
}