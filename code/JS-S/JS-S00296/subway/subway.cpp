#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int k[4];
int a[4][500005];
int w[4][500005];
int ww[500005];
void sol1(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int num[500005];
    for(int i=1;i<=m;i++){
        cin>>ww[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a[j][i]>>w[j][i], num[a[j][i]]+=w[j][i];
    }
    sort(num+1,num+n+1);
    int aa, bb;
    for(int i=1;i<=q;i++){
        cin>>aa>>bb;
        int fa=0,fb=0;
        for(int j=1;j<=k[1];j++){
            if(aa==a[1][j])fa=1;
            if(bb==a[1][j])fb=1;
        }
        if(fa^fb)cout<<num[m]+ww[aa]+ww[bb]<<' ';
        else cout<<ww[aa]+ww[bb];

    }
}
int main(){
    cin>>c>>n>>m>>d>>q;
    if(c==20||c==21)sol1();
    return 0;
}
