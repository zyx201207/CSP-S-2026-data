#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int x[100005],y[100005];
int w[500005];
int k[505];
int a[505][500005];
int t[505][500005];
int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    if(c>=12 && c<=19){
        int T=t[1][1];

    }
    return 0;
}//I L X Q Y
