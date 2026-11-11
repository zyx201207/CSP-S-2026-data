#include<bits/stdc++.h>
#define getchar getchar_unlocked
using namespace std;
using ll=long long;
constexpr int MAXM=5e5+5,MAXN=502,MAXQ=1e2+2,INF=0x3f3f3f3f;
struct way{
    int to;
    int cost;
};
int w[MAXM]={},k[MAXN]={},a[MAXN][MAXM]={},t[MAXN][MAXM]={},c,n,m,q,d,x,y;

vector<way> sta[MAXN]={};

//In way i,No.j station is a[i][j]
//t[i][j]:The time from way i to station a[i][j]
vector<way> ways[MAXN]={};
bool cc[MAXN]={};
int fastin(){
    int n=0,b=1;
    char c=getchar();
    if(c=='-'){
        b=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        n*=10;
        n+=c-'0';
        c=getchar();
    }
    return n*b;
}
int dijkstra();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway1.in","r",stdin);
    //freopen("subway.out","w",stdout);
    //preeeeeee
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];

    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            sta[a[i][j]].push_back({i,t[i][j]});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(auto it:sta[a[i][j]]){
                ways[i].push_back({it.to,t[i][j]+it.cost});
            }
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x>>y;
        int cost=w[x]+w[y];
        cost+=dijkstra();
        cout<<cost<<endl;
    }
}
struct stu{
    int pos;
    int cost;
};
class prique{
private:
    list<stu> l;
public:
    int size(){return l.size();}
    int empty(){return l.empty();}
    void push(stu a){
        if(l.empty()){l.insert(l.begin(),a);return;}
        for(auto it=l.begin();it!=l.end();it++){
            if(it->cost>a.cost){
                l.insert(prev(it),a);
            }
        }
    }
    stu front(){return *l.begin();}
    void pop(){l.pop_front();}
};
int dijkstra(){
    prique qu;
    for(auto it:sta[x])qu.push({it.to,it.cost});
    while(!qu.empty()){
        stu now=qu.front();
        cout<<"In dijkstra:"<<now.pos<<' '<<now.cost<<endl;
        qu.pop();
        if(cc[now.pos]==1){
            continue;
        }
        for(auto it:sta[y]){
            if(now.pos=it.to){
                return now.cost;
            }
        }
        cc[now.pos]=1;
        for(auto it:ways[now.pos]){
            if(cc[it.to]==0){
                qu.push({it.to,now.cost+it.cost});
            }
        }
    }
}
