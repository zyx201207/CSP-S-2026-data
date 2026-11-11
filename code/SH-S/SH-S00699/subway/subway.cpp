#include<bits/stdc++.h>
#define int int64_t
#define cin fin
#define cout fout
#define INF INT64_MAX
using namespace std;
ifstream fin("subway.in");
ofstream fout("subway.out");
struct Node{
    int from,to,weight;
    Node(){}
    Node(int a,int c,int b){
        from=a;to=c;weight=b;
    }
    bool operator>(const Node b)const{
        return weight>b.weight;
    }
};
struct ufs{
    vector<int> fa;
    int getroot(int t){
        if(t!=fa[t]){
            fa[t]=getroot(fa[t]);
        }
        return fa[t];
    }
    void un(int a,int b){
        int ra=getroot(a),rb=getroot(b);
        fa[ra]=rb;
    }
    ufs(int a){
        fa.resize(a+1);
        for(int i=1;i<=a;i++){
            fa[i]=i;
        }
    }
};
int c,n,m,d,q;//应该不会被认为是骂人吧（
int timer=1;
vector<int> in,ord;
vector<int> out;
vector<int> tmp;
vector<int> fa[13],dep;
map<pair<int,int>,int> mp;
map<pair<int,int>,int> nmp;
void dfs(int c,int f,int de){
    in[c]=timer++;
    ord.push_back(c);
    tmp[in[c]]=nmp[(pair<int,int>){f,c}];
    fa[0][c]=f;
    dep[c]=de;
    for(int i=1;i<=n;i++){
        if(i==c||i==f)continue;
        if(nmp.count({c,i})){
            dfs(i,c,de+1);
        }
    }
    out[c]=timer++;
    tmp[out[c]]=-nmp[(pair<int,int>){f,c}];
}
int LCA(int a,int b){
    if(dep[a]>dep[b])swap(a,b);
    for(int k=12;k>=0;k--){
        if(dep[a]<=dep[fa[k][b]]){
            b=fa[k][b];
        }
    }
    if(b==a){
        return b;
    }
    for(int k=12;k>=0;k--){
        if(fa[k][a]!=fa[k][b]){
            b=fa[k][b];
            a=fa[k][a];
        }
    }
    return fa[0][a];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m+5);
    for(int i=1;i<=m;i++)cin>>w[i];
    vector<vector<pair<int,int>>> cr(m+5);
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        for(int j=0;j<t;j++){
            int a,ti;
            cin>>a>>ti;
            cr[a].push_back(make_pair(i,ti));
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<cr[i].size();j++){
            for(int k=j+1;k<cr[i].size();k++){
                if(mp.count({cr[i][j].first,cr[i][k].first})){
                    mp[(pair<int,int>){cr[i][j].first,cr[i][k].first}]=min(mp[(pair<int,int>){cr[i][j].first,cr[i][k].first}],cr[i][j].second+cr[i][k].second);
                }else{
                    mp[(pair<int,int>){cr[i][j].first,cr[i][k].first}]=cr[i][j].second+cr[i][k].second;
                }
                mp[(pair<int,int>){cr[i][k].first,cr[i][j].first}]=mp[(pair<int,int>){cr[i][j].first,cr[i][k].first}];
            }
        }
    }//最多2e8次
    priority_queue<Node,vector<Node>,greater<Node>> que;
    ufs u(n);
    for(int j=1;j<=n;j++){
        for(int k=j+1;k<=n;k++){
            if(mp.count({j,k})){
                que.push(Node(j,k,mp[{j,k}]));
            }
        }
    }

    while(!que.empty()){
        Node cur=que.top();
        que.pop();
        if(u.getroot(cur.from)==u.getroot(cur.to))continue;
        u.un(cur.from,cur.to);
        nmp[(pair<int,int>){cur.from,cur.to}]=cur.weight;
        nmp[(pair<int,int>){cur.to,cur.from}]=cur.weight;
    }


    in.resize(n+1);
    out.resize(n+1);
    for(int i=0;i<13;i++)fa[i].resize(n+1);
    dep.resize(n+1);
    tmp.resize(2*n+1);
    dfs(1,1,1);

    for(int i=1;i<=2*n;i++){
        tmp[i]+=tmp[i-1];
    }
    for(int i=0;i<=n;i++){
        int c=ord[i];
        for(int k=1;k<13;k++){
            fa[k][c]=fa[k-1][fa[k-1][c]];
        }
    }
    for(int r=1;r<=q;r++){
        int x,y;
        cin>>x>>y;
        int ans=INT64_MAX;
        for(int i=0;i<cr[x].size();i++){
            for(int j=0;j<cr[y].size();j++){
                ans=min(ans,tmp[in[cr[x][i].first]]+tmp[in[cr[y][j].first]]-2*tmp[in[LCA(cr[x][i].first,cr[y][j].first)]]+cr[x][i].second+cr[y][j].second);
            }
        }
        cout<<w[x]+w[y]+ans<<'\n';
    }
}
//我是蒟蒻。
//感觉代码时间复杂度好高
//虽然能过所有样例
