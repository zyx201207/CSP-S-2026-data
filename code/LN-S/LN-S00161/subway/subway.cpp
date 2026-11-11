#include<bits/stdc++.h>
using namespace std;
struct jh{
    int x,y;
};
int w[500001],a[501][21],t[501][21];
jh r[100001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,temp;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
            cin>>temp;
        for(int j = 1;j<=temp;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    int sum = 0;
    for(int i = 1;i<=q;i++){
        cin>>r[i].x>>r[i].y;
        for(int j = 1;j<=r[i].y;j++){
            sum+=t[1][j];
        }
        cout<<w[1]+t[1][1]+sum;
    }
    return 0;
}
