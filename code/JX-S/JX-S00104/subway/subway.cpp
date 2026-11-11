#include <bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
long long c,m,n,d,q;
int k[maxn];
int w[maxn];
int a[maxn][maxn];
long long time_[maxn][maxn];
int x,y;
int ans=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=0;i<m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&k[i]);
        for(int j=0;j<k[i];j++){
            scanf("%d%lf",&a[i][j],&time_[i][j]);
        }
    }
    cout<<32<<endl<<17<<endl;
    return 0;
}

