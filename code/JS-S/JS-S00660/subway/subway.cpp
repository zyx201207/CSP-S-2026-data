#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
struct node{
    int v,w;
};
vector<node> g[N+10000];
int c, n, m, d, q,w[N],k[505],s,e,dis[1005][1005];
int main(){
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m+n;i++){
    for(int j=1;j<=m+n;j++){
        dis[i][j]=dis[j][i]=100000000;
    }
}
for(int i=1;i<=m;i++)cin>>w[i];
int t1,t2;
for(int i=1;i<=n;i++){
    cin>>k[i];
    for(int j=1;j<=k[i];j++){
        cin>>t1>>t2;
        dis[t1][m+i]=t2;
        dis[m+i][t1]=t2;
    }
}
for(int i=1;i<=m+n;i++)dis[i][i]=0;
for(int i=1;i<=m+n;i++){
    for(int j=1;j<=m+n;j++){
        for(int k=1;k<=m+n;k++){
            dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
}
while(q){
    cin>>s>>e;
    if(s==e){
        cout<<0<<"\n";
        q--;
        continue;
    }
    cout<<w[e]+w[s]+dis[s][e]<<"\n";
    q--;
}
return 0;
}
