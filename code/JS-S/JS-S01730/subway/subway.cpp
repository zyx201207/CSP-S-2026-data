#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll station;
    ll plat;
}a[505][1005];
struct point{
    ll line;
    ll wz;
};
vector<point>v[500005];
int lena[505];
ll c,n,m,d,q;
ll ti[500005];
ll mintime;
bool book[505][500005];
void dfs(ll line,ll sta,ll alltime,ll goal){
    if(a[line][sta].station==0){
        return;
    }
    if(a[line][sta].station==goal){
        mintime=min(mintime,alltime+a[line][sta].plat);
        return;
    }
    dfs(line,sta+1,alltime+a[line][sta].plat+a[line][sta+1].plat,goal);
    int x=a[line][sta].station;
    for(int i=0;i<(int)v[x].size();i++){
        if(book[v[x][i].line][v[x][i].wz]){
            continue;
        }
        book[v[x][i].line][v[x][i].wz]=1;
        dfs(v[x][i].line,v[x][i].wz,alltime+a[line][sta].plat+a[v[x][i].line][v[x][i].wz].plat,goal);
        book[v[x][i].line][v[x][i].wz]=0;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>ti[i];
    }
    ll k;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            //if(i==1&&j==1){
            //    cout<<"ok\n";
            //}
            cin>>a[i][j].station>>a[i][j].plat;
            //cout<<a[i][k].station<<"\n";
            v[a[i][j].station].push_back({i,j});
        }
    }

    ll x,y;

    while(q--){
        //pair<ll,ll>x_line[500005]={0};
        //ll xlinelen=0;
        cin>>x>>y;
        memset(book,0,sizeof(book));
        //for(int i=1;i<=n;i++){
        //    for(int j=1;j<=lena[i];j++){
        //        if(a[i][j].station==x){
        //            x_line[++xlinelen]=make_pair(i,j);
        //        }
        //    }
        //}
        mintime=114514114514;
        for(int i=0;i<v[x].size();i++){
            //cout<<a[1][1].plat<<"\n";
            dfs(v[x][i].line,v[x][i].wz,-a[v[x][i].line][v[x][i].wz].plat,y);

        }
        cout<<mintime+ti[x]+ti[y]<<"\n";
    }
    //for(int i=0;i<v[2].size();i++){
    //    cout<<v[2][i].line<<" "<<v[2][i].wz<<"\n";
    //}
    return 0;
}
//orz rp++ csp-s 2= made by cici
