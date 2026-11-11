#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
int a[N];
int b[N][N];
int c[N][N];
int z,n,m,d,q;
int main(){
    cin>>z>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=2;j++){
            cin>>c[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=q;i++){
        int x=c[1],y=c[2];
        for(int j=0;j<=2;j++){
            ans=ans+x+y;
            ans=ans+b[1][3]*(y-1);
        }
        cout<<ans;
    }

    return 0;
}
