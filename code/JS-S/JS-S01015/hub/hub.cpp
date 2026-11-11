#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
    int n=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
bool Mbe;
int c,t;
int n,k;
vector<int> e[1000005];
vector<int> son[1000005];
int sz[1000005];
int dep[1000005];
void dfs_init(int x,int f){
    for(auto v:e[x]){
        if(v==f)continue;
        son[x].push_back(v);
        dep[v]=dep[x]+1;
        dfs_init(v,x);
    }
}
short dp[4005][8005][2][3];
short ne[8005][2][3];
int lim;    
//most shallow controlled from i dist j-> j+sz[x]
//deepest uncontrolled from i dist j->j 0<=j<sz[x]
void chk(short &x,short y){
    x=min(x,y);
}
void dfs(int x,int f){
    sz[x]=1;
    if(son[x].empty()){
        dp[x][1][1][1]=1;
        dp[x][0][0][0]=0;
        return;
    }
    dp[x][1][1][1]=1;
    dp[x][0][0][0]=0;
    for(auto v:son[x])dfs(v,x);
    for(auto v:son[x]){
        for(int i=0;i<(sz[x]+sz[v])*2;i++){
            for(int j=0;j<2;j++)for(int k=0;k<3;k++){
                ne[i][j][k]=n*2;
            }
        }
        for(int i=0;i<sz[x]*2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    if(dp[x][i][j][k]>n)continue;
                    for(int w=0;w<sz[v]*2;w++){
                        for(int y=0;y<2;y++){
                            for(int z=0;z<3;z++){
                                if(dp[v][w][y][z]>n)continue;
                                int nk=k+z;
                                if(j&&y)nk--;
                                if(nk>2)continue;
                                int ni=-1;
                                if(i<sz[x]&&w<sz[v]){
                                    ni=max(i,w+1);
                                    if(ni>=lim)ni=-1;
                                }
                                else if(i>=sz[x]&&w<sz[v]){
                                    if(i-sz[x]+1+w<=lim){
                                        ni=i-sz[x]+sz[x]+sz[v];
                                    }
                                    else{
                                        if(w+1>=lim)ni=-1;
                                        else ni=w+1;
                                    }
                                }
                                else if(i<sz[x]&&w>=sz[v]){
                                    if(w-sz[v]+1+i<=lim){
                                        ni=w-sz[v]+1+sz[v]+sz[x];
                                    }
                                    else{
                                        if(i>=lim)ni=-1;
                                        else ni=i;
                                    }
                                }
                                else{
                                    ni=min(i-sz[x],1+w-sz[v])+sz[x]+sz[v];
                                }
                                if(ni>=0)chk(ne[ni][j][nk],dp[x][i][j][k]+dp[v][w][y][z]);
                            }
                        }
                    }
                }
            }
        }
        sz[x]+=sz[v];
       // cout<<"MERGED "<<x<<" "<<v<<"\n";
        for(int i=0;i<sz[x]*2;i++){
            for(int j=0;j<2;j++)for(int k=0;k<3;k++){
                dp[x][i][j][k]=ne[i][j][k];
               // if(dp[x][i][j][k]<=n)cout<<x<<" "<<i<<" "<<j<<" "<<k<<":"<<dp[x][i][j][k]<<"\n";
            }
        }
    }
}
bool check(int x){
    for(int i=1;i<=n;i++)for(int j=0;j<=2*n;j++)for(int k=0;k<2;k++){
        for(int x=0;x<3;x++)dp[i][j][k][x]=n*2;
    }
    lim=x;
    dfs(1,0);
    for(int i=n;i<=2*n;i++){
        for(int j=0;j<2;j++){
            for(int x=0;x<3;x++){
                if(dp[1][i][j][x]<=k){
                   // cout<<i<<" "<<j<<" "<<x<<" "<<dp[1][i][j][x]<<"\n";
                    return 1;
                }
            }
        }
    }
    return 0;
}
void solve(){
    n=read(),k=read();
   //n=4000,k=n-1;
    for(int i=1;i<=n;i++)e[i].clear(),son[i].clear(),dep[i]=0;
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        //int u=i,v=i+1;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs_init(1,0);
    if(k==n){
        cout<<0<<"\n";
        return;
    }
    //check(1);
    //return;
    int l=1,r=n;
    int res=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))res=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<res<<"\n";
}
namespace SOLVER{
    int n,k,K;
vector<int> e[1000005];
vector<int> son[1000005];
int sz[1000005];
int dep[1000005];
void dfs_init(int x,int f){
    for(auto v:e[x]){
        if(v==f)continue;
        son[x].push_back(v);
        dep[v]=dep[x]+1;
        dfs_init(v,x);
    }
}
int dp[500005][11][2][3];
int ne[11][2][3];
int lim;    
//most shallow controlled from i dist j-> j+sz[x]
//deepest uncontrolled from i dist j->j 0<=j<sz[x]
int get(int i,int w,int x,int v){
    int ni=-1;
    if(i<sz[x]&&w<sz[v]){
        ni=max(i,w+1);
        if(ni>=lim)ni=-1;
    }
    else if(i>=sz[x]&&w<sz[v]){
        if(i-sz[x]+1+w<=lim){
            ni=i-sz[x]+sz[x]+sz[v];
        }
        else{
            if(w+1>=lim)ni=-1;
            else ni=w+1;
        }
    }
    else if(i<sz[x]&&w>=sz[v]){
        if(w-sz[v]+1+i<=lim){
            ni=w-sz[v]+1+sz[v]+sz[x];
        }
        else{
            if(i>=lim)ni=-1;
            else ni=i;
        }
    }
    else{
        ni=min(i-sz[x],1+w-sz[v])+sz[x]+sz[v];
    }
    return ni;
}
void chk(int &x,int y,int S){
    if(y==-1)return;
    if(x==-1){
        x=y;
        return;
    }
    if(x<S){
        if(y>=S)x=y;
        else x=min(x,y);
    }
    else if(y>=S){
        x=min(x,y);
    }
}
void dfs(int x,int f){
    sz[x]=1;
    if(son[x].empty()){
        dp[x][1][1][1]=1;
        dp[x][0][0][0]=0;
        return;
    }
    dp[x][1][1][1]=1;
    dp[x][0][0][0]=0;
    for(auto v:son[x])dfs(v,x);
    for(auto v:son[x]){
        for(int i=0;i<=K;i++){
            for(int j=0;j<2;j++)for(int k=0;k<3;k++){
                ne[i][j][k]=-1;
            }
        }
        for(int i=0;i<=K;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    if(dp[x][i][j][k]==-1)continue;
                    for(int w=0;w<=K;w++){
                        for(int y=0;y<2;y++){
                            for(int z=0;z<3;z++){
                                if(dp[v][w][y][z]==-1)continue;
                                int nk=k+z;
                                if(j&&y)nk--;
                                if(nk>2)continue;
                                int ni=-1;
                                ni=get(dp[x][i][j][k],dp[v][w][y][z],x,v);
                                if(ni>=0&&i+w<=K)chk(ne[i+w][j][nk],ni,sz[x]+sz[v]);
                            }
                        }
                    }
                }
            }
        }
        sz[x]+=sz[v];
       // cout<<"MERGED "<<x<<" "<<v<<"\n";
        for(int i=0;i<=K;i++){
            for(int j=0;j<2;j++)for(int k=0;k<3;k++){
                dp[x][i][j][k]=ne[i][j][k];
               // if(dp[x][i][j][k]<=n)cout<<x<<" "<<i<<" "<<j<<" "<<k<<":"<<dp[x][i][j][k]<<"\n";
            }
        }
    }
}
bool check(int x){
    for(int i=1;i<=n;i++)for(int j=0;j<=K;j++)for(int k=0;k<2;k++){
        for(int x=0;x<3;x++)dp[i][j][k][x]=-1;
    }
    lim=x;
    dfs(1,0);
    for(int i=0;i<=k;i++){
        for(int j=0;j<2;j++){
            for(int x=0;x<3;x++){
                int val=dp[1][i][j][x];
                if(val==-1)continue;
                if(val<n)continue;
                if(val>=n&&val-n>=lim)continue;
                if(dp[1][i][j][x]!=-1){
                    //cout<<i<<" "<<j<<" "<<x<<" "<<dp[1][i][j][x]<<"\n";
                    return 1;
                }
            }
        }
    }
    return 0;
}
void solve(){
    n=read(),k=read();K=k;
   //n=4000,k=n-1;
    for(int i=1;i<=n;i++)e[i].clear(),son[i].clear(),dep[i]=0;
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        //int u=i,v=i+1;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs_init(1,0);
    if(k==n){
        cout<<0<<"\n";
        return;
    }
    //check(178);
    //return;
    int l=1,r=n;
    int res=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))res=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<res<<"\n";
}
}
bool Med;
signed main(){
    //cerr<<(&Mbe-&Med)/1048576.00<<"MB\n";
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),t=read();//c=11;
    if(c==11||c==12||c==15){
        while(t--)SOLVER::solve();
        return 0;
    }
   // t=3;
    while(t--)solve();
    return 0;
}
/*
g++ -std=c++14 -O2 -Wall -Wextra -Wshadow hub.cpp -o hub && ./hub

ulimit -s 998244353

Hey, it's me, it's Verity
Ask me anything
(oh I've got a question)
I know about a million things
I'll do everything
(ok) Oh what is the capital of France
oh oui oui oui
It is Paris
Merci
Oh what does the cow say
Oh moo moo moo
I speak that too
all day
Do you live alone
Is anybody home
1 2 3 and so....
Where did everybody go???
Hey it's me it's Verity
Ask me anything
I know about a million things
I'll do everything
Oh why's the door locked up so tight?
Oh tee hee hee
No need to leave
Stay here
why do you know where I sleep???
Oh I just know
I always know
I'm close
Do you live alone
Is anybody home
1 2 3 and so....
Where did everybody go???
come
Come closer
Come be my friend
Dont be so scared (Love me!!!)
Hey it's me it's Verity
Ask me anything
I know about a million things
I'll do everything
*/
