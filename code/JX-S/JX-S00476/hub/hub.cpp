#include<bits/stdc++.h>
using namespace std;
#define int long long
int inline read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();};
    while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();};
    return x*f;
}
const int N=2e6+10;
int c,t;
int tot,head[N<<1],tot,to[N<<1],nx[N<<1];
void add(int u,int v){
    nx[++tot]=head[u];
    to[tot]=v;
    head[u]=tot;
}
void solve(){
    memset(head,0,sizeof(head));tot=0;
    int n,k;
    n=read(),k=read();
    for(int i=1;i<n;i++){
        int u,v;
        u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    cout<<((n+1)/2)/4-k/4+1;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    c=read(),t=read();
    while(t--)solve();
    return 0;
}