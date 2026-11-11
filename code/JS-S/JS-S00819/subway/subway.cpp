/*
g++ subway.cpp -o subway -std=c++14 -O2 -Wall
1. pushup & pushdown
2. int overflow? ll space? __int128?
3. guess bravely
4. constant factor VS. log
5. don't be afarid of countings.
6. is the sample large enough?

diff subway1.out subway1.ans
diff subway2.out subway2.ans
diff subway3.out subway3.ans
diff subway4.out subway4.ans
diff subway5.out subway5.ans
diff subway6.out subway6.ans
diff subway7.out subway7.in
*/
#include<bits/stdc++.h>
using namespace std;
#define y0 xcxakioi
#define y1 fcyakioi
#define x0 XCXAKIOI
#define x1 FCYAKIOI
namespace File{
    void Redirect(string s){
        ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        string Istr=s+".in",Ostr=s+".out";
        freopen(Istr.c_str(),"r",stdin),freopen(Ostr.c_str(),"w",stdout);
    }
}

#define int long long
const int N=505,M=500005;
int dis[N][N],n,m,d,q;
int ext[M];
vector<pair<int,int>> way[M];
main(){
    srand(time(0)),File::Redirect("subway");
    cin>>n>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>ext[i];
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        int k,stt,len;
        cin>>k;
        while(k--){
            cin>>stt>>len;
            way[stt].push_back({i,len});
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int D=way[i].size();
        for(int L=0;L<D;L++)for(int R=L+1;R<D;R++){
            int u=way[i][L].first,v=way[i][R].first,w=way[i][L].second+way[i][R].second;
            dis[u][v]=min(dis[u][v],w),dis[v][u]=min(dis[v][u],w);
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int l,r,ans=1e18;
        cin>>l>>r;
        for(int L=0;L<way[l].size();L++)for(int R=0;R<way[r].size();R++)ans=min(ans,way[l][L].second+way[r][R].second+dis[way[l][L].first][way[r][R].first]);
        cout<<ext[l]+ext[r]+ans<<'\n';
    }
}
/*
14:40 T1
14:45 why is T2 so hard
14:50 it's 800
15:05 T2?
15:10 T2!
*/