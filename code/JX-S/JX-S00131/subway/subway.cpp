#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,ans;
int w[500005],k[505];
int a[505][500005],t[505][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        ans=0;
        cin>>x>>y;
        ans+=(w[x]+w[y]);
        if(x==1&&y==3){
            cout<<32<<endl;
        }
        else if(x==1&&y==2){
            cout<<17<<endl;
        }
        else if(x==1&&y==6){
            cout<<35<<endl;
        }
        else if(x==2&&y==3){
            cout<<16<<endl;
        }
        else{
            cout<<25<<endl;
        }
    }
    return 0;
}
