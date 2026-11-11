#include <bits/stdc++.h>
using ll=long long;
using namespace std;
constexpr int MAXN=505,MAXM=500005;
int sgates[MAXM];
vector<pair<int,int>/*i,w*/> slines[MAXM];
vector<pair<int,int>/*i,w*/> lstas[MAXN];
ll sdist[MAXN],ldist[MAXN];
bitset<MAXN> lvisited;
bitset<MAXM> svisited;
struct SearchNode{
    bool isSta;
    int idx;
    ll searchDist;
    ll& dist(){
        return isSta?sdist[idx]:ldist[idx];
    }
    ll dist_const()const{
        return isSta?sdist[idx]:ldist[idx];
    }
    void setVisited(){
        if(isSta) svisited[idx]=1;
        else lvisited[idx]=1;
    }
    SearchNode();
    SearchNode(bool isSta,int idx,int searchDist):isSta(isSta),idx(idx),searchDist(searchDist){}
};
bool operator>(const SearchNode& x,const SearchNode& y){
    return x.dist_const()>y.dist_const();
}
int main(){
    FILE* _f=freopen("subway.in","r",stdin);
    _f=freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++) cin>>sgates[i];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        lstas[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>lstas[i][j].first>>lstas[i][j].second;
            --lstas[i][j].first;
            slines[lstas[i][j].first].emplace_back(i,lstas[i][j].second);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        --x,--y;
        memset(sdist,0x3f,sizeof(sdist));
        memset(ldist,0x3f,sizeof(ldist));
        lvisited.reset();svisited.reset();
        priority_queue<SearchNode,vector<SearchNode>,greater<SearchNode>> Q;
        SearchNode firstnd(1,x,sgates[x]+sgates[y]);
        firstnd.dist()=firstnd.searchDist;
        firstnd.setVisited();
        Q.push(firstnd);
        bool flag=0;
        while(!Q.empty()){
            SearchNode node=Q.top();Q.pop();
            if(node.searchDist>node.dist()) continue;
            if(node.isSta){
                for(auto lpair:slines[node.idx]){
                    if(lvisited[lpair.first]) continue;
                    // if(lstas[lpair.first].size()==1) continue;
                    SearchNode newnode(0,lpair.first,node.searchDist+lpair.second);
                    newnode.dist()=newnode.searchDist;
                    newnode.setVisited();
                    Q.push(newnode);
                }
            }else{
                for(auto spair:lstas[node.idx]){
                    if(svisited[spair.first]) continue;
                    // if(slines[spair.first].size()==1) continue;
                    SearchNode newnode(1,spair.first,node.searchDist+spair.second);
                    if(newnode.idx==y){
                        cout<<newnode.searchDist<<'\n';
                        flag=1;
                        break;
                    }
                    newnode.dist()=newnode.searchDist;
                    newnode.setVisited();
                    Q.push(newnode);
                }
            }
            if(flag) break;
        }
    }
    return 0;
}