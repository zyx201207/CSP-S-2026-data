#include<bits/stdc++.h>
using namespace std;
int m,n,d,q,c,same;
long long sum;
string w;//time from exit to subway
int a[513][500013],t[513][500013],r[100013][2],k[513];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2*k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i][0]>>r[i][1];
    }
    same=t[1][1];
    for(int i=1;i<=q;i++){
        cout<<r[i][0]<<endl;
    }
    return 0;
}
