#include<bits/stdc++.h>
using namespace std;
int w[500001];
int k[501];
int a[501][500001],j[501][500001];
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
            cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int l=1;l<=k[i];++l){
            cin>>a[i][l]>>j[i][l];
        }
    }
    int x,y;
    int sum=0;
    for(int h=1;h<=q;++h){
        cin>>x>>y;
        sum=sum+w[x]+w[y];
        if(n<=3&&d<=20&&m<=10){

        }
    }
    return 0;
}
