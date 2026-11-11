#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r","stdin")
    freopen("subway.out","w","stdout")
    coust int M=5e5+8
    long long c,n,m,d,p,k[508],a[508][M],t[508][M],e[M],w1[M],w2[M],minn[508][M],pd[508];
    cin>>c>>n>>m>>d>>p;
    long long pd[508][M]
    for(int i=1;i<=n;i++){
        cin>>w1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=2;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            w2[a][i][j]=t[i][j];
            pd[i][a][i][j]=ture;
            for(size_t z=0;i<e[a][i][j].size();i++){
                int v=e[a[i][j]];
                minn[i][v]=min(minn[i][v].t[i][j]+t[v][a[i][v]]);
            }
            e[a[i][j]].push_back(1);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,flag=0;
        long long ans=0;
        cin>>x>>y;
        ans+=w1[x]+w1[y]+w2[x]+w2[y];
        for(int i=1;i<=n;i++){
            if(pd[i][x] & pd[i][y]){
                cout<<ans;
                flag=1;
                break;
            }
            if(flag) continue;
            queue<int>q;
            for(size_t j=0;j<e[x].size();j++){
                q.push(e[x][j]);
                while()
            }
        }
    }
    reture 0;
}

