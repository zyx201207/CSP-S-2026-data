#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005],t[505][505];
int a[505][505],k[505],x[505],y[505];
int main(){
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    cout<<s
    return 0;

}
