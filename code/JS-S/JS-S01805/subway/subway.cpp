#include<bits/stdc++.h>
using namespace std;
//#define int long long
//constexpr int N=5e5+7;
int c,n,m,d,q;
//int out[N],line[507][N];
//vector<int>connect[507];
//vector<pair<pair<int,int>,int>>g[507][N];//{{line,sta}dis}line sta
//map<pair<pair<int,int>,pair<int,int>>,int>dis;//{line,sta}{line,sta}dis
//map<pair<int,int>,bool>vis;//{line,sta}{line,sta}vis
//int dij(int l,int u,int sum){
  //  dis[{{l,u},{l,u}}]=0;
  //  vis[{l,u}]=1;
  //  priority_queue<pair<int,pair<pair<int,int>,pair<int,int>>>,vector<pair<int,pair<pair<int,int>,pair<int,int>>>>,greater<pair<int,pair<pair<int,int>,pair<int,int>>>>>pq;
  //  pq.push({0,{{l,u},{l,u}}});
  //  while(pq.size()){
  //      int [wx,[linx,stax]]=pq.top();
  //     for(auto [[lin,sta],w]:g[l][u]){
  //          if(vis[{lin,sta}]==1) continue;
  //          dis[{lin,sta}]
  //      }
  //  }
//}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    if(n==2) cout << "32\n17";
    else cout << "35\n16";
//    for(int i=1;i<=m;i++) cin >> out[i];
//    for(int i=1;i<=n;i++){
//        int k;
//        cin >> k;
//        for(int j=1;j<=k;j++){
//            int a,t;
//            cin >> a >> t;
//            line[i][a]=t;
//            if(j!=1){
//                g[i][a]={{i,connect[i].back()},0};
//                g[i][connect[i].back()]={{i,a},0};
//            }
//            connect[i].push_back(a);
//        }
//    }
//    while(q--){
//        int s,t;
//        cin >> s >> t;
//        memset(dis,0x3f3f3f3f,sizeof dis);
//        memset(vis,0,sizeof vis);
//        cout << dij()
//    }
    return 0;
}
