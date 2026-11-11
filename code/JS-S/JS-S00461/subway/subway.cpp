#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll maxs=500006,maxs2=502;
ll c,n,m,d,q,w[maxs],x[maxs],y[maxs],k[maxs];
vector<ll>a[maxs2];
vector<ll>t[maxs2];
struct pp2{
    ll st,line;
};
struct pp3{
    ll tl,line;
};
struct ppp{
    vector<ll>line;//the postion of line[i]
    ll sizeforline;
    vector<pp2>sta;//the stations have one road
    ll sizeforsta;
    ll getinout;//the time for getting in or out
    vector<pp3>tline;//the time for line[i];
    ll sizefortline;
}s[maxs];
inline ll read(){
    ll a=0;
    char c=getchar();
    bool pd=0;
    while(c<'0'||c>'9'){
        if(c=='-')pd=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        a=a*10+c-'0';
        c=getchar();
    }
    if(pd==1)a*=-1;
    return a;
}
bool comp(pp3 a,pp3 b){
    return a.line<b.line;
}
void djs(ll x,ll y){
    queue<ll>station;
    station.push(x);
    bool change=1;
    ll t[maxs];
    while(change==1){
        ll now=station.front();
        station.pop();
        for(int i=1;i<=s[now].sizeforsta;i++){
            ll p=lower_bound(s[now].line.begin(),s[now].line.end(),s[now].sta[i].line)-s[now].line.begin();
            if(s[now].line[p]==s[now].sta[i].line){
                if(t[s[now].sta[i].st]>t[now]){
                    t[s[now].sta[i].st]=t[now];
                    station.push(s[now].sta[i].st);
                }
            }else{

            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
        s[i].getinout=w[i];
    }
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            ll ak=read(),tk=read();
            a[i].push_back(ak);
            t[i].push_back(tk);
        }
    }
    for(int i=1;i<=q;i++){
        x[i]=read();
        y[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            s[a[i][j]].line.push_back(i);
            s[a[i][j]].sizeforline++;
            if(j>1){s[a[i][j]].sta.push_back({a[i][j-1],i});s[a[i][j]].sizeforsta++;}
            if(j<k[i]){s[a[i][j]].sta.push_back({a[i][j+1],i});s[a[i][j]].sizeforsta++;}
            s[a[i][j]].tline.push_back({t[i][j],i});
        }
    }
    for(int i=1;i<=m;i++){
        sort(s[i].tline.begin(),s[i].tline.end(),comp);
        sort(s[i].line.begin(),s[i].line.end());
    }
    for(int i=1;i<=q;i++){
        printf("%lld\n",s[x[i]].getinout+s[y[i]].getinout);
    }
    return 0;
}
