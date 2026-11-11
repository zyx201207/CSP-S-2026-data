#include<bits/stdc++.h>
using namespace std;
#define int long long
int b,n,m,d,q;
int a[500010];
int c[500010][2];
struct node{
    int placeee;
    int timeee;
};
list<node> ct[500010];
int ans=LONG_LONG_MAX;
bool isvisited[500010];
void go(int x,int y,int z){
    if(x==z){
        ans=min(ans,y);
        return;
    }
    isvisited[x]=1;
    for(auto e=ct[x].begin();e!=ct[x].end();e++){
        if(isvisited[(*e).placeee]==0){
            go((*e).placeee,y+(*e).timeee,z);
        }
    }
    isvisited[x]=0;
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>b>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        int t;
        cin>>t;
        memset(c,0,sizeof(c));
        for(int i=1;i<=t;i++){
            cin>>c[i][0]>>c[i][1];
        }
        for(int i=1;i<=t;i++){
            for(int j=i+1;j<=n;j++){
                node t1;
                t1.placeee=c[j][0];
                t1.timeee=c[i][1]+c[j][1];
                ct[i].push_back(t1);
                node t2;
                t1.placeee=c[i][0];
                t1.timeee=c[i][1]+c[j][1];
                ct[j].push_back(t2);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int t3,t4;
        cin>>t3>>t4;
        ans=0;
        memset(isvisited,0,sizeof(isvisited));
        go(t3,0,t4);
        cout<<ans+a[t3]+a[t4]<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
