#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int rd(){
    int x=0;bool f=0;char c=getchar_unlocked();
    while((c<'0'||c>'9')&&c!='-')c=getchar_unlocked();
    if(c=='-')f=1,c=getchar_unlocked();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar_unlocked();
    if(f)return -x;
    return x;
}
ll rdll(){
    ll x=0;bool f=0;char c=getchar_unlocked();
    while((c<'0'||c>'9')&&c!='-')c=getchar_unlocked();
    if(c=='-')f=1,c=getchar_unlocked();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar_unlocked();
    if(f)return -x;
    return x;
}
ll x[100005];
vector<int>e[100005];
bool inq[100005];
ll dis[100005];
int cnt[100005];
int n;
bool spfa(int s){
    memset(inq,0,sizeof(inq));
    memset(dis,0x3f,sizeof(dis));
    memset(cnt,0,sizeof(cnt));
    queue<int>q;
    q.push(s);
    inq[s]=1;
    dis[s]=0;
    cnt[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(int v:e[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                cnt[v]=1;
                q.push(v);
            }else if(dis[v]==dis[u]+1){
                cnt[v]++;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==2){
            res++;
            //cout<<s<<' '<<i<<'\n';
        }
    }
    return res;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=rd(),t=rd();
    while(t--){
        n=rd();
        ll d=rdll();
        for(int i=1;i<=n;i++){
            x[i]=rdll();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(abs(x[j]-x[i])<=d){
                    e[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int cc=spfa(i);
            ans+=cc;
            //cout<<cc<<'\n';
        }
        cout<<ans/2<<"\n";
        //cout<<'\n';
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
    }
    return 0;
}
//There is a surprise down!!
















































































//Go down quickly!!






























































































//Never gonna give you up~~
//Never gonna let you down~~
//Never gonna run around and desert you~~
//Never gonna make you cry~~
//Never gonna say goodbye~~
//Never gonna tell a lie and hurt you~~
//But I really thank you very much, because... this is my last year to take part in OI competition (in middle school).Yeah, I'm in Grade 9.(Okay you are "never gonna give you up"ed again)
//2026/10/31 18:13 ---yycYM
