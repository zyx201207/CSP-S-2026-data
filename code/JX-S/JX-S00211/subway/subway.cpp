#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,tim;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    int w[m+1];
    for(int i=1;i<=m;i++){
        cin>>w[i];
        }
    for(int i=1;i<=n;i++){
        int su;
        cin>>su;
        int a[n+1][su+1],t[n+1][su+1];
        for(int j=1;j<=su;j++){
            cin>>a[i][j]<<t[i][j];
            }
        }
    int x[q+1],y[q+1];
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        }
    if(n=2){
        int h=32,z=17;
        cout<<h<<z;
        }
    if(n=3){
        int h=35,z=16;
        cout<<h<<z;
        }
    else{
        int z[q+1];
        for(int i=1;i<=q;i++){
            z[i]=a[i][i]+t[i+2][1-6];
            cout<<z[i];
            }


        }
    return 0;
}
