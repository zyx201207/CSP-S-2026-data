#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
struct node{
    int to,va;
};
vector<node> ma[N];
int di(int st,int ed){
    int dis[N];
    bool vi[N];
    for(int i=1;i<=m;i++){
        vi[i]=0;
    }
    for(int i=1;i<=m;i++) dis[i]=INT_MAX;
    dis[st]=0;
    for(int i=1;i<=m;i++){
        int minnum=INT_MAX,pos;
        for(int j=1;j<=m;j++) {
            if(!vi[j]) {
                if(minnum>dis[j]){
                     minnum=dis[j];
                     pos=j;
                }
            }
        }

        for(int j=0;j<ma[pos].size();j++){

            int po2=ma[pos][j].to,va2=ma[pos][j].va;

            if(!vi[po2]&&dis[pos]+va2<dis[po2]) dis[po2]=dis[pos]+va2;
        }
        vi[pos]=1;
    }

    return dis[ed];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int a0,b0;
        for(int j=1;j<=k;j++){

            int a,b;
            cin>>a>>b;
            if(j>1){

                ma[a].push_back({a0,b+b0});

                ma[a0].push_back({a,b+b0});
            }

            a0=a,b0=b;
        }
    }

    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        cout<<di(u,v)+w[u]+w[v]<<endl;
    }
    return 0;
}
