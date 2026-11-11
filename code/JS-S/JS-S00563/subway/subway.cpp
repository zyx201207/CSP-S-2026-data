#include<bits/stdc++.h>
#define gc getchar
#define pc putchar
#define mp make_pair
#define pck putchar(' ')
#define pcn putchar('\n')
#define pb push_back
#define fir first
#define sec second
#define int long long


using namespace std;

typedef pair<int,int> pii;

int read(){
    int k=1,x=0;
    char ch=gc();
    while(ch!='-' && !isdigit(ch)){
        ch=gc();
    }
    if(ch=='-'){
        k=-1;
        ch=gc();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return k*x;
}

void print(int x){
    if(x<0){
        pc('-');
        x=-x;
    }
    if(x<10){
        pc(x^48);
        return;
    }
    print(x/10);
    pc((x%10)^48);
}

void freop(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
}

int w[500500];

struct node{
    int v,w;
    node(int _v,int _w){
        v=_v,w=_w;
    }
};

vector<node> G[550];
int dis[550][550];
bool vis[550];

int tmp_g[550][550];
void dij(int x){
    memset(vis,0,sizeof(vis));
    dis[x][x]=0;
    priority_queue<pii> q;
    q.push(mp(0,x));
    while(!q.empty()){
        int u=q.top().sec;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].v,w=G[u][i].w;
            if(dis[x][u]+w<dis[x][v]){
                dis[x][v]=dis[x][u]+w;
                q.push(mp(-dis[x][v],v));
            }
        }
    }
}

vector<pii> haveline[500500];
//fir:line_id sec:time

signed main(){
    freop();
    int testod=read(),n=read(),m=read(),d=read(),T=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int id=read(),walktime=read();
            haveline[id].pb(mp(i,walktime));
            //cout<<"WALK"<<walktime<<endl;
        }
    }
    memset(tmp_g,0x3f,sizeof(tmp_g));
    for(int i=1;i<=m;i++){
        for(int x=0;x<haveline[i].size();x++){
            for(int y=x+1;y<haveline[i].size();y++){
                tmp_g[haveline[i][x].fir][haveline[i][y].fir]=min(tmp_g[haveline[i][x].fir][haveline[i][y].fir],haveline[i][x].sec+haveline[i][y].sec);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(tmp_g[i][j]==0x3f3f3f3f3f3f3f3f)continue;
            G[i].pb((node){j,tmp_g[i][j]});
            G[j].pb((node){i,tmp_g[i][j]});
            //cout<<"addedge("<<i<<','<<j<<','<<tmp_g[i][j]<<')'<<endl;
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dij(i);
    }
    while(T--){
        int x=read(),y=read();
        int ans=0x3f3f3f3f3f3f3f3f;
        for(int line1=0;line1<haveline[x].size();line1++){
            for(int line2=0;line2<haveline[y].size();line2++){
                int line1id=haveline[x][line1].fir;
                int line2id=haveline[y][line2].fir;
                int line1tm=haveline[x][line1].sec;
                int line2tm=haveline[y][line2].sec;
                //cout<<"checked"<<' '<<line1id<<' '<<line2id<<endl;
                ans=min(ans,w[x]+w[y]+dis[line1id][line2id]+line1tm+line2tm);
            }
        }
        print(ans),pcn;
    }
    return 0;
}
/*
Time 14:30-18:30 don't forget!

luogu:AutumnQ(uid=1038710)
friend:moon_set

chennie,Cubber,absi2011,cmh,aaa_Pigeaon,offoff,Sving1024,placeholder,hyman00,UKB_wyx,TheSky233,LXGOD,rym,SNRJ,moon_set bless me!
The participant who sits next to me says that he is qqiq,is this true?

rp=inf;

15:06 Maybe think out T2.
15:34 WA on Sample #3.
15:43 Maybe AC T2, Running #7 206ms.
*/