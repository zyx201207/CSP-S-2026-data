#include <bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005],x[3],y[3];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k1,k2,sum1=0,sum2=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int j1=1;j1<=k1*2;j1++){
        if(j1==1){
            cin>>k1;
            sum1+=k1;
        }
        cin>>b[j1];
        sum1+=b[j1];
    }
    for(int j=1;j<=k2*2;j++){
        if(j==1){
            cin>>k2;
            sum2+=k2;
        }
        if(j<=5){
            sum2+=b[j];
        }
    }
    for(int i=1;i<=2;i++){
        cin>>x[i];
    }
    for(int i=1;i<=2;i++){
        cin>>y[i];
    }
    cout<<sum1+m<<endl;
    cout<<sum2+y[2];
    return 0;
}
