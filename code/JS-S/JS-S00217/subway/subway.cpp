#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int n,m,c,d,q,ans;
int w[maxn];
int e[2005][2005];
int cur[maxn];
vector<int> es[maxn];

int volyd(){
    for(int k=1;k<=m+n;k++){
        for(int i=1;i<=m+n;i++){
            for(int j=1;j<=m+n;j++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    return 0;
}
int bfs(int l,int r){

    for(int i=1;i<=m+n;i++)cur[i]=0;
    queue<int> q;
    q.push(l);
    while(!q.empty()){

        int fr=q.front();
        q.pop();
        for(auto v:es[fr]){
            if(cur[v]==0){
                cur[v]=cur[fr]+1;
                if(v==r){
                    return cur[v];
                }
                q.push(v);
            }
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(e,0x3f,sizeof(e));
    cin>>c>>n>>m>>d>>q;
    int clf=1;
    if(m>1500)clf=0;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int checkf=0,checkans=1;
    for(int i=1;i<=n;i++){
        int k=0;
        int a,t;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            if(clf){
                e[m+i][a]=t;
                e[a][m+i]=t;
            }



            if(checkans){
                es[m+i].push_back(a);
                es[a].push_back(m+i);

            if(checkf==0){
                checkf=t;
            }else if(checkf!=t){
                checkans=0;
            }
            }
        }
    }
    if(checkans){
        //bfs();
    }else
    if(clf){
        volyd();
    }
    while(q--){
        int l;
        int r;
        cin>>l>>r;
        if(clf){
            cout<<e[l][r]+w[l]+w[r]<<'\n';
        }else if(checkans){
            cout<<bfs(l,r)*checkf+w[l]+w[r]<<'\n';
        }

    }
    return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
