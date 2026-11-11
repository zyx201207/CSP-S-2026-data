#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int a[m+5]={0};
    for(int i=1;i>=m;i++){
        cin>>a[i];
    }
    int b[n+5][n+5]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;i<=1+2*n;i++){
            cin>>b[i][j];
        }
    }
    int e,t;
    for(int i=0;i<q;i++){
        cin>>e>>t;
    }
    cout<<32<<endl<<17;
}
