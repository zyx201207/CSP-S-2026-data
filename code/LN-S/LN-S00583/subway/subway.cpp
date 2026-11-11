#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M=5e5+10;
const int N=510;
struct station{
    int idx;
    int time;
    vector<int> totai[N];
}a[M];
vector<pair<int,int> >e[M];//e[i]{x0,y0,z1} i和x/y有直接联系 i和z需要换乘
int ans=0;
bool vis[M];
void dfs(int x,int dist,int cnt){
    if(x==dist){
        ans=min(cnt,ans);
        return;
    }
    for(pair<int,int> u:e[x]){
        if(!vis[u.first]){
            vis[u.first]=1;
            dfs(u.first,dist,cnt+u.second);//继续沿着当前的路线走
            vis[u.first]=0;
            for(int j=0;j<N;j++){//考虑换乘
                if(totai[j][0]!=0){
                    dfs();//沿着前方走
                    dfs();//向后走
                }else{
                    break;//不再有可以换乘的车站了
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        a[i].idx=i;
        cin>>a[i].time;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int last=-1;
        for(int j=1;j<=k;j++){
            if(last!=-1){
                int u,k;
                cin>>u>>k;
                e[last].push_back({u,0});
                e[u].push_back({last,0});
                a[u].totai[i].push_back(k);//totai[i][x]=k 意思：第i条线路的第x个车站从站台走到站厅需要k分钟
                last=u;
            }else{
                cin>>last;
                int k;
                cin>>k;
                a[last].totai[i].push_back({k});
            }
        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        dfs(x,y,a[x].time+e[x].second);
        cout<<ans<<endl;
    }
    return 0;
}
/*
5
10

1->2
2->3
3->4
4->5
5->6
6->7
7->8
8->9
9->10
*/


//
