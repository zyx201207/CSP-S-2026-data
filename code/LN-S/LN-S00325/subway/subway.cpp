#include<bits/stdc++.h>
using namespace std;

int zhan[505][23],zh[505][23];
int num[2000];
int w[500050],a[505][1010];
int x[100050],y[100050];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c, n, m, d, q;
    cin>>c, n, m, d, q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
            cin>>num[a[i][j]];
        }
    }

    for(int i=1;i<=q;i++){
        int x;int y;
        cin>>x>>y;
        cout<<w[x]+w[y]+num[x]+num[y]<<endl;
    }
    return 0;
}
