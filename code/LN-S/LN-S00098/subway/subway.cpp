#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=5e5+5;
inline int read(){
    int x=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c-'0');
        c=getchar_unlocked();
    }
    return x*f;
}
struct sta{
    int line,ti,id;
};
int c,n,m,d,q;
int w[N];
int ans=-666666666;
vector<sta> station[N];
vector<int> trans[N][N];
vector<int> ln[N];
bool tran[N];
bool vis[N];
void travel(int s,int f,int l,int t,int idx){
    for(int i=0;i<ln[l].size();i++){
        if(ln[l][i]==f){
            ans=max(t+station[f][idx].ti+w[f],ans);
            return;
        }
    }
    for(int i=0;i<ln[l].size();i++){
        int x=ln[l][i];
        if(tran[s]){
            int i=0;
            for(auto y:station[x]){
                if(!vis[y.line]) travel(y.id,f,y.line,t+station[x][i].ti+station[y.id][i].ti,i);
                i++;
            }
        }
        vis[l]=1;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int a=read();
            int b=read();
            station[a].pb({i,b,a});
            ln[i].pb(a);
        }
    }
    //chuli huanchengchan
    for(int i=1;i<=m;i++){
        if(station[i].size()>1){
            tran[i]=true;
            for(auto s:station[i]){
                for(auto t:station[i]){
                    trans[s.id][t.id].pb(i);
                    trans[t.id][s.id].pb(i);
                }
            }
        }
    }
    //zhengpian kaishi
    while(q--){
        int u=read(),v=read();
        int i=0;
        for(auto x:station[u]){
            travel(u,v,x.line,w[x.id]+x.ti,i);
            i++;
        }
        printf("%lld",ans);
        ans=-6666666;
    }
    return 0;
}
//17:40
//fk,why do you baocuo?
//R_X86_64_PC32 against symbol 'ln' defined in .bss section in /home/noi_dlu/subway/subway.o
//what it means?
//?+0+0+0
//how to NOIP
//rp++ pls
//pls CCF
//I love CCF very much!
