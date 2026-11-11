#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int a[100005]={},c=0,n=0,m=0,d=0,q=0;
    int zx[100000][100000]={};
    int zy[100000][100000]={};
    int w[1000]={};
    int v[1000]={};
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x=0;
        cin>>x;
        for(int j=1;j<=x;j++){

            cin>>zx[i][j]>>zy[i][j];
        }
    }

    for(int i=1;i<=q;i++){

        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=q;i++){
        int sum=0;
        int f=0,g=0;
        f=w[i];
        g=v[i];
        sum=sum+a[f]+a[g];
        f=zy[1][1];
        g=v[i]-w[i];
        sum=sum+f*g;
        cout<<sum<<endl;
    }
    return 0;
}
