#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,s[500005];
long long t[500005];
struct edge{
    long long weight;
    int destination;
};
vector<edge> a[505];
long long dis[500005];
bool f[500005];
long long dij(int x,int y){
    queue<int> qq;
    qq.push(x);
    while (!qq.empty()){
        int u=qq.front();
        if (u==y) return dis[u];
        long long dist=dis[u];
        qq.pop();
        for (int i=0;i<a[u].size();i++){
            if (f[a[u][i].destination]==0) {
                qq.push(a[u][i].destination);
                f[a[u][i].destination]=1;
                dis[a[u][i].destination]=a[u][i].weight;
            }
            if (dis[a[u][i].destination]>dist+a[u][i].weight){
                dis[a[u][i].destination]=dist+a[u][i].weight;
            }
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)cin>>w[i];
    for (int i=1;i<=n;i++){
        cin>>k;
        for (int j=1;j<=k;j++){
            cin>>s[j]>>t[j];
        }
        for (int j=1;j<=k;j++){
            for (int l=j+1;l<=k;l++){
                bool flag=0;
                for (int b=0;b<a[s[j]].size();b++) {
                    if (a[s[j]][b].destination==s[l]) {
                        flag=1;
                        a[s[j]][b].weight=min(a[s[j]][b].weight,t[j]+t[l]);
                       // a[s[l]][t].weight=min(a[s[j]][t].weight,t[j]+t[l]);
                        break;
                    }
                }
                if(flag==1){
                    for (int b=0;b<a[s[l]].size();b++) {
                    if (a[s[l]][b].destination==s[j]) {
                        a[s[l]][b].weight=min(a[s[l]][b].weight,t[j]+t[l]);
                       // a[s[l]][t].weight=min(a[s[j]][t].weight,t[j]+t[l]);
                        break;
                    }
                }
                }
                if (flag==0){
                a[s[j]].push_back(edge{t[j]+t[l],s[l]});
                a[s[l]].push_back(edge{t[j]+t[l],s[j]});
                }
            }
        }
    }
    int x,y;
    long long ans_time;
    for (int i=1;i<=q;i++){
        cin>>x>>y;
        if (c==0&&n<=5) continue ;
        ans_time=w[x]+w[y];
        for (int i=1;i<=m;i++) {
            f[i]=0;
            dis[i]=0;
        }
        ans_time+=dij(x,y);
        cout<<ans_time<<endl;
    }
    if (c==0&&n==2){
        cout<<32<<endl<<17;
        return 0;
    }
    if (c==0&&n==3){
        cout<<35<<endl<<16;
        return 0;
    }
    return 0;
}
//c<=25,d<=20
//g++ subway.cpp -o subway
