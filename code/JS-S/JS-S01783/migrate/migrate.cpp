#include<bits/stdc++.h>
using namespace std;

#define int long long
namespace io{
    int read(){
        int k=0,f=1;
        char c=getchar_unlocked();
        while(c<'0'||c>'9'){
            if(c=='-'){
                f=-1;
            }
            c=getchar_unlocked();
        }
        while(c>='0'&&c<='9'){
            k=k*10+c-'0';
            c=getchar_unlocked();
        }
        return k*f;
    }
    void write(int x){
        if(x<0){
            putchar('-');
            x=-x;
        }
        if(x<10){
            putchar(x+'0');
        }else{
            write(x/10);
            putchar(x%10+'0');
        }
    }
    template<class T>void read(T&x){x=read();}
    template<class First,class... Args>void read(First&first,Args&... arg){read(first);read(arg...);}
    template<class T>void write(T x){write(x);}
    template<class First,class... Args>void write(First first,Args... arg){write(first);write(arg...);}
}
using namespace io;

int n,d;
void dfs(int dep,int u,vector<int>&x,vector<int>&indeg,vector<int>&dist){
    // cerr<<u<<" ";
    if(dep<dist[u]){
        dist[u]=dep;
        indeg[u]=1;
    }else if(dep==dist[u]){
        indeg[u]++;
        // if(u==6&&dep==2) cerr<<"*";
    }
    for(int i=u+1;i<=n&&x[i]-x[u]<=d;i++){
        dfs(dep+1,i,x,indeg,dist);
    }
}
const int inf=1e18+10;
void baoli_solve(){
    read(n,d);
    vector<int>x(n+1),indeg;
    vector<int>dist;
    for(int i=1;i<=n;i++){
        read(x[i]);
    }
    // cerr<<"A"<<endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        dist.assign(n+1,inf);indeg.assign(n+1,0);
        dfs(0,i,x,indeg,dist);
        for(int j=i+1;j<=n;j++){
                // cerr<<i<<" "<<j<<" "<<dist[j]<<" "<<indeg[j]<<endl;
            if(indeg[j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
void solveA(){
    read(n,d);
    vector<int>x(n+1);
    for(int i=1;i<=n;i++){
        read(x[i]);
    }
    if(n==1){
        write(0);
        putchar('\n');
        return;
    }
    int gc=x[2]-x[1];
    // cerr<<gc<<" "<<n<<" "<<d<<endl;
    if(d<2*gc){
        putchar('0');putchar('\n');
    }else{
        // cerr<<n<<" "<<2*(d/gc)<<endl;
        if(n>=2*(d/gc)){
            write(n-1-2*(d/gc-1));putchar('\n');
        }else{
            putchar('0');putchar('\n');
        }
    }
    return ;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    read(C,T);
    if(C==11||C==12){
        while(T--){
            solveA();
        }
        return 0;
    }
    // cerr<<C<<" "<<T<<endl;
        // while(T--){
        //     solveA();
        // }
        // return 0;
    while(T--){
        baoli_solve();
    }
    return 0;
}