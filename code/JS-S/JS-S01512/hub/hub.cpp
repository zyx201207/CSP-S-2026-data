#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
vector<int>a[110];
bitset<10>sel;
bool h[110];
int flag;
void dfs(int p,int dep){
    h[p]=1;
    if(flag!=-1) return ;
    if(sel[p-1]){
        flag=dep;
        return ;
    }
    for(int q:a[p]){
        if(h[q]) continue;
        dfs(q,dep+1);
    }
    return ;
}
void dfs2(int p,int col){
    h[p]=col;
    // cout<<p<<' '<<col<<endl;
    for(int q:a[p]){
        // cout<<p<<' '<<q<<' '<<h[q]<<' '<<sel[q-1]<<endl;
        if(h[q]!=0||sel[q-1]==0) continue;
        // cout<<p<<' '<<q<<endl;
        dfs(q,col);
    }
    return ;
}
void solve1(){
    int n=read();
    int k=read();
    for(int i=1;i<=n;i++){
        a[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;
        u=read();
        v=read();
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans=0x7fffffffff;
    for(int i=0;i<1<<n;i++){
        sel=i;
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=sel[j];
        }
        if(cnt!=k) continue;
        // for(int j=0;j<n;j++){
        //     cout<<sel[j]<<' ';
        // }
        // cout<<endl;
        flag=0;
        memset(h,0,sizeof h);
        for(int j=0;j<n;j++){
            if(sel[j]==1&&h[j+1]==0){
                flag++;
                dfs2(j+1,flag);
            }
        }
        // cout<<flag<<endl;
        if(flag>2) continue;
        int maxn=-1;
        for(int j=0;j<n;j++){
            if(sel[j]) continue;
            flag=-1;
            memset(h,0,sizeof h);
            dfs(j+1,0);
            maxn=max(maxn,flag);
            // cout<<j+1<<' '<<flag<<endl;
        }
        ans=min(ans,maxn);
        // for(int j=0;j<n;j++){
        //     cout<<sel[j]<<' ';
        // }
        // cout<<maxn<<endl;
    }
    write(ans);
    putchar('\n');
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=read();
    int _=read();
    while(_--){
        if(c<=3) solve1();
    }
    return 0;
}