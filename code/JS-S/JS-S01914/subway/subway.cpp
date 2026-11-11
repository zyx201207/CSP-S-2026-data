#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int line,cost;
};
int const N=5e5+5;
int w[505];
ll vis[505][25];
bool flag;
int s,t;
ll ans=LONG_LONG_MAX;
map<int,int> sta[505];
vector<int> line[N];
void dfs(int pre_sta,int line_before,int id,ll cost){
    //cout<<"***"<<line_before<<" "<<id<<" "<<cost<<endl;
    if(id==t){
        ans=min(ans,cost);
        return;
    }
    for(auto i:sta[id] ){
        for(auto j:line[i.first] ){
            //cout<<i.first<<" "<<j<<endl;
            if(j==id||j==pre_sta){
                continue;
            }
            //cout<<id<<"->"<<j<<" "<<cost<<" "<<line_before<<"  "<<i.first<<" "<<(i.first==line_before ?0 :i.second)<<" "<<sta[j][i.first]<<endl;
            if(id==3&&j==6){
                //cout<<"&&&&&&&&&&&&"<<vis[i][i.first]<<" "<<cost<<endl;
            }
            if(vis[id][i.first]>cost){
                vis[id][i.first]=cost;
               // cout<<"true"<<endl;
                dfs(id,i.first,j,cost+(i.first==line_before ?0 :sta[j][i.first])+(i.first==line_before ?0 :i.second));
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=m;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
            sta[a][i]=t;
            line[i].push_back(a);
        }
    }
    while(q--){
        memset(vis,0x3f,sizeof(vis));
        flag=0;
        ans=LONG_LONG_MAX;
        scanf("%d%d",&s,&t);
        dfs(-1,-1,s,0LL);
       // cout<<ans<<endl;
        printf("%lld\n",w[s]+ans+w[t]);
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
*/
