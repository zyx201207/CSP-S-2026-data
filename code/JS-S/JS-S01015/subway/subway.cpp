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
int c,n,m,D,q;
int w[500005];
vector<pair<int,int>> e[500005];
int d[505][505];
bool Med;
signed main(){
    //cerr<<(&Mbe-&Med)/1048576.00<<"MB\n";
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),D=read(),q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=0;j<k;j++){
            int x=read(),t=read();
            e[x].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<(int)e[i].size();j++){
            for(int k=0;k<(int)e[i].size();k++){
                int u=e[i][j].first,v=e[i][k].first;
                d[u][v]=d[v][u]=min(d[u][v],e[i][j].second+e[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
    while(q--){
        int x=read(),y=read();
        int co=w[x]+w[y];
        int res=1ll<<60;
        for(auto v1:e[x]){
            for(auto v2:e[y]){
                res=min(res,co+v1.second+v2.second+d[v1.first][v2.first]);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
/*
g++ -std=c++14 -O2 -Wall -Wextra -Wshadow subway.cpp -o subway

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
