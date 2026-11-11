#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,n,m,d,Q;
int a[N];
int sta[N];
int t[N];
int dst[N][N];
void slove(){
    int s,e;
    cin>>s>>e;
    cout<<dst[s][e]+a[s]+a[e]<<'\n';
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dst[i][j]=1e9;
        }
    }
    for(int i=1;i<=n;i++){
        int stas;
        cin>>stas;
        for(int j=1;j<=stas;j++){
            cin>>sta[j]>>t[j];
        }
        for(int j=1;j<=stas;j++){
            for(int k=j+1;k<=stas;k++){
                dst[sta[j]][sta[k]]=t[k]+t[j];
                dst[sta[k]][sta[j]]=t[k]+t[j];
 //               cout<<sta[j]<<" "<<sta[k]<<" "<<t[k]+t[j]<<'\n';
            }
        }
    }
    for(int i=1;i<=m;i++)dst[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++){
                dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
            }
        }
    }
    while(Q--){
        slove();
    }
}

