#include<bits/stdc++.h>
using namespace std;
long long w[10000],k[10000],a[501][1000],t[501][1000],x[10000],y[10000];
long long uy[100];
int main(){
    long long c,n,m,d,q;
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
    int ans;
    if(c==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(t[i][j]==t[i][j+1]&&t[i][j]==t[i+1][j]){
                    ans=0;
                }
                else{
                    ans++;
                }
            }
        }
        if(ans==0){
            for(int i=1;i<=q;i++){
                uy[i]=(y[i]-x[i])*t[1][1];
            }
        }
        for(int i=1;i<=n;i++){
            int g=0;
            for(int j=1;j<=k[i];j++){
                if(x[i]==a[i][j]||y[i]==a[i][j]){
                    g++;
                }
            }
            if(g=2){
                cout<<uy[i];
            }
        }
    }
    return 0;
}
