#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int N=600;
const int M=5e5+5;

int c,n,m,d,q;
int w[N];
int a[N][M],t[N][M];
int f[M][M];

signed main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        for(int j=1;j<=l;j++){
            cin>>a[i][j]>>t[i][j];
            if(j>1){
                f[a[i][j-1]][a[i][j]]=f[a[i][j]][a[i][j-1]]=
                t[i][j-1]+t[i][j];
            }
        }
    }


    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=f[i][k]+f[k][j];
            }
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=w[l]+w[r];
        ans+=f[l][r];
        cout<<ans<<'\n';
    }

}
