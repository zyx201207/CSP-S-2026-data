#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
//#define cat human
vector<int>w;
vector<vector<int>>tim,f,ff;
vector<bool>kl;
int mn=3221225477;//bushi
bool fc=0;
inline int read(){
    char ch=getchar();int f=1,k=0;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){k=(k<<1)+(k<<3)+ch-'0';ch=getchar();}
    return k*f;
}
void bfs(int a,int b,int ans){
    if(a==b){
        mn=min(mn,ans);fc=0;
    }
    else{
        rep(i,0,f[a].size()){
            rep(j,0,ff[f[a][i]].size()){
                if(kl[ff[f[a][i]][j]]==0){
                    kl[ff[f[a][i]][j]]=1;
                    if(ff[f[a][i]][j]!=a)bfs(ff[f[a][i]][j],b,ans+tim[f[a][i]][a]+tim[f[a][i]][ff[f[a][i]][j]]);
                    kl[ff[f[a][i]][j]]=0;
                }
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    c=read(),n=read(),m=read(),d=read(),q=read();
    w.resize(m);
    f.resize(m),ff.resize(n);
    kl.resize(m,0);
    tim.resize(n,vector<int>(m));
    rep(i,0,m)w[i]=read();
    rep(i,0,n){
        int k=read();
        rep(j,0,k){
            int x=read();
            x--;
            f[x].push_back(i);//station=>railway
            ff[i].push_back(x);//railway=>station
            tim[i][x]=read();//railway+station=>time
        }
    }
    rep(i,0,q){
        mn=INT_MAX;
        int a=read(),b=read(),ans=w[a-1]+w[b-1];
        a--,b--;
        bfs(a,b,0);
        cout<<mn+ans<<'\n';
    }
}
