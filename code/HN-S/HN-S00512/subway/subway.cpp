#include <bits/stdc++.h>
using namespace std;
#define int long long
int W[1200005];
vector<int> A[600005],tim[600005];
int f[525][525];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>W[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=1e18;
        }
        f[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int Siz;
        cin>>Siz;
        for(int j=1;j<=Siz;j++){
            int to,zhi;
            cin>>to>>zhi;
            A[to].push_back(i);
            tim[to].push_back(zhi);
        }
    }
    for(int i=1;i<=m;i++){
        for(int id1=0;id1<A[i].size();id1++){
            for(int id2=id1+1;id2<A[i].size();id2++){
                int num1=A[i][id1],num2=A[i][id2];
                f[num1][num2]=min(f[num1][num2],tim[i][id1]+tim[i][id2]);
                f[num2][num1]=min(f[num2][num1],tim[i][id1]+tim[i][id2]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int Len=1e18;
        for(int id1=0;id1<A[x].size();id1++){
            for(int id2=0;id2<A[y].size();id2++){
                int num1=A[x][id1],num2=A[y][id2];
                Len=min(Len,f[num1][num2]+tim[x][id1]+tim[y][id2]);
            }
        }
        cout<<Len+W[x]+W[y]<<'\n';
    }
    return 0;
}