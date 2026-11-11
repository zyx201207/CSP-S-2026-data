#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
struct lxz{
    int w;
    long long len;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    /*vector<int> g[2*m+n];
    int h[2*m+n+5][2*m+n+5];
    for(int i=0;i<2*m+n+5;i++){
        for(int j=0;j<2*m+n+5;j++){
            h[i][j]=0;
        }
    }*/
    for(int i=1;i<=m;i++){
        cin>>w[i];
        /*g[i].push_back(m+i);
        g[m+i].push_back(i);
        h[i][m+i]=w[i];
        h[m+i][i]=w[i];*/
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            /*g[a+m].push_back(2*m+i);
            g[2*m+i].push_back(a+m);
            h[2*m+i][a+m]=t;
            h[a+m][2*m+i]=t;*/
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+5<<endl;
        /*queue<lxz> q;
        bool v[2*m+n+5];
        memset(v,0,sizeof(v));
        q.push({x,0});
        v[x]=1;
        while(!q.empty()){
            lxz now=q.front();
            q.pop();
            cout<<now.w<<'@'<<now.len<<endl;
            if(now.w==y){
                cout<<now.len<<endl;
                break;
            }
            for(int i=0;i<g[now.w].size();i++){
                cout<<g[now.w][i]<<' ';
                if(!v[g[now.w][i]]){
                    q.push({g[now.w][i],now.len+h[g[now.w][i]][now.w]});
                    v[g[now.w][i]]=1;
                }
            }
            cout<<endl;
        }*/
    }
    return 0;
}
