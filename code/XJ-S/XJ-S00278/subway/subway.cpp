#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
const int N=5e5+10;
class node{
public:
    int v,val;
    friend bool operator<(const node &x,const node &y){
        return x.val<y.val;
    }
};
int c,n,m,d,q;
int w[N],dis[N];
std::vector<node> e[N];
void dij(int now){
    std::priority_queue<node> q;
    std::memset(dis,0x3f,sizeof(dis));
    dis[now]=0;
    q.push((node){now,dis[now]});
    while(!q.empty()){
        auto ww=q.top();
        q.pop();
        int u=ww.v;
        for(auto www:e[u]){
            int v=www.v,val=www.val;
            if(dis[v]>dis[u]+val){
                dis[v]=dis[u]+val;
                q.push((node){v,dis[v]});
            }
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        std::cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        std::cin>>k;
        std::vector<int> a(k),t(k);
        for(int j=0;j<k;j++){
            std::cin>>a[j]>>t[j];
        }
        for(int j=0;j<k;j++){
            for(int z=0;z<k;z++){
                if(j==z) continue;
                e[a[j]].push_back((node){a[z],t[j]+t[z]});
                e[a[z]].push_back((node){a[j],t[j]+t[z]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        std::cin>>x>>y;
        dij(x);
        std::cout<<dis[y]+w[x]+w[y]<<"\n";
    }
    return 0;
}