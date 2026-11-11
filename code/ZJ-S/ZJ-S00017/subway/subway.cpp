#include<bits/stdc++.h>
using namespace std;
#define N 2005
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
vector <pii> eg[N];
bool f[N];ll dis[N];
int a[N],t[N],t2[N];
int main(){
    //我T2暴力都调不出来 我这几年是不是白学了 
    //我这活着还有啥意义 好绝望 我感觉我这辈子完了
    //连个蓝钩都拿不到 90分 丢不丢脸
    //高二了 这么把whk放一边来博这个OI 真的值得吗
    //别活了 你这个fvv 投入这么多时间 精力 成本 就让你写个90出场的吗？
    //老师 教练 家人 自己 多大的期待 你就这么辜负了 打这么点分 赶紧退役吧
    //都等着看你笑话呢 你真是fvv 你有啥用
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;//station gap as the 2n-1 station
    for(int i=1;i<=m;++i){
        int x;
        cin>>x;
        t2[i]=x;
        eg[i].push_back({m+i,x});
        eg[m+i].push_back({i,x});
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<=k;++j){
            for(int z=j+1;z<=k;++z){
                eg[m+j].push_back({a[z]+m,t[j]});
                eg[a[z]+m].push_back({m+j,t[j]});
            }
        }
    }
    while(q--){
        memset(dis,0x3f,sizeof(dis));
        int x,y;
        cin>>x>>y;
        priority_queue <pli,vector<pli>,greater<pli > > q;
        q.push({0,x});
        f[x]=1;
        while(!q.empty()){
            auto p=q.top();q.pop();
            ll u=p.first;int v=p.second;
            for(auto e:eg[v]){
                int p1=e.first,p2=e.second;
                if(f[p1]){
                    continue;
                }
                if(dis[v]>dis[p1]+p2){
                    dis[v]=dis[p1]+p2;
                    f[p1]=1;
                    q.push({dis[v],p1});
                }
            }
        }
        cout<<dis[y]<<'\n';
        memset(f,0,sizeof(f));
    }
    return 0;
}