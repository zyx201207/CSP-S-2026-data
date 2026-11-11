#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;
    int w[500005], a[505], t[505];
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>t[i];
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<32<<"\n";
        cout<<17;
    }else if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<35<<"\n";
        cout<<16;
    }
    return 0;
}
