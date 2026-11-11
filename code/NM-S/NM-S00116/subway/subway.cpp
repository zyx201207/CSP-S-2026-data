#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
int k[505],t[505][500005];
int s,goal;
void wyt(int q,int z){

}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
        }
    }
    for(int i=1;i<=q;++i){
        cin>>s>>goal;
    }

    return 0;
}
