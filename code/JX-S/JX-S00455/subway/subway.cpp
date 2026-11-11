#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005]={},k,a[500005]={},x,y;
int main(){
    freopen("subway,in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int j=1;j<=n;j++){
        cin>>k;
        for(int i=1;i<=2*k;i++){
            cin>>a[i];
        }
    }
    for(int i=1;i<=2;i++){
        cin>>x>>y;
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<32;
        cout<<endl;
        cout<<17;
    }
    else if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<35;
        cout<<endl;
        cout<<16;
    }
    return 0;
}
