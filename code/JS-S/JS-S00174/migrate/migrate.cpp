#include <bits/stdc++.h>
using namespace std;
int main(){
    int c,t,h=0;
    cin>>c>>t;
    for(int k=1;k<=t;k++){
        int n,d;
        cin>>n>>d;
        int ans=0;
        int x[n+5];
        int a[n+5][n+5],b[n+5][n+5];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    a[i][j]=1;
                    a[j][i]=1;
                }
            }
        }
        for(int i=4;i<=n;i++){
            h=1;
            for(int h=1;h<i;h++){
                if(a[h][i]==1){
                    for(int g=1;g<h;g++){
                        if(a[g][h]==1){
                            b[i][g]++;
                        }
                    }
                }
            }
        }
        for(int i=4;i<=n;i++){
            for(int j=1;j<i;j++){
                if(b[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    return 0;
}