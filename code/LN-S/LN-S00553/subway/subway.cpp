#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
int c,n,m,d,q,minn=INT_MAX,b,e;
int w[MAXN],t[505][MAXN],a[505][MAXN];
bool v[MAXN]={false};
vector <int> g[MAXN];
void dfs(int x,int time,int gd){
    if(x==e){
        time+=w[e];
        minn=min(minn,time);
        return;
    }
    v[x]=true;
    time+=t[gd][x];
    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int k=1;k<=g[i].size();k++){
            if(x==g[i][k]) flag =true;

        }
        if(flag==true){
            for(int j=1;j<=g[i].size();j++){
                if(!v[j]) {
                    time+=t[x][i];
                    dfs(g[i][j],time,i);
                }

            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>d>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            g[i].push_back(j);
        }
    }
    while(q--){

        cin>>b>>e;
        dfs(b,w[b],0);
        cout<<minn<<endl;
        minn=INT_MAX;
        memset(v,false,sizeof(v));
    }

    return 0;
}
