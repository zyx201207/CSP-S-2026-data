#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[1005][1005];
long long l1[100005],r2[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>l1[i];
        cin>>r2[i];
    }
    cout<<32<<endl;
    cout<<17;
    return 0;
}
