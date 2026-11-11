#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m,q,c,d,k,t[505][MAXN];
bool a[505][MAXN];
long long w[MAXN];
queue<int> qu;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int to;
            cin>>to;
            a[i][to]=true;
            cin>>t[i][to];
        }
    }
    while(q--){
        int x,y;
        long long be[MAXN];
        bool th[MAXN];
        cin>>x>>y;
        for(int i=1;i<=m;i++){
            be[i]=92233720;
            th[i]=false;
        }
        be[x]=w[x];
        qu.push(x);
        while(!qu.empty()){
            int now=qu.front();
            qu.pop();
            th[now]=true;
            for(int i=1;i<=n;i++){
                if(a[i][now]){
                    for(int j=1;j<=m;j++){
                        if(a[i][j]&&!th[j]){
                            qu.push(j);
                            be[j]=min(be[j],be[now]+t[i][now]+t[i][j]);
                        }
                    }
                }
            }
        }
        be[y]+=w[y];
        cout<<be[y]<<endl;
    }
    return 0;
}
