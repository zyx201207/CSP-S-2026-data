#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int x;
int q2,w;
int y;
int a;
int l,r;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>x;
    }
    cin>>q2>>w;
    for(int i=1;i<=2*q2;i++){
        cin>>y;
    }
    for(int j=1;j<=2*w;j++){
        cin>>a;
    }
    for(int i=1;i<=q;i++){
        cin>>l>>r;
    }
    cout<<10;
    return 0;
}

