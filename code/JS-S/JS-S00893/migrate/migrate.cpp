#include <bits/stdc++.h>
using namespace std;
int c,t,n,a[305][305][2];
long long d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        bool f=1;
        long long c,ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        c=x[2]-x[1];
        for(int i=2;i<n;i++){
            if(x[i+1]-x[i]!=c){
                f=0;
                break;
            }
        }
        if(n<=300){
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(abs(x[i]-x[j])<=d) a[i][j][0]=a[j][i][0]=a[i][j][1]=a[j][i][1]=1;
                    else a[i][j][0]=a[j][i][0]=1e9,a[i][j][1]=a[j][i][1]=0;
                }
            }
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(i==k||i==j||j==k) continue;
                        if(a[i][k][0]+a[k][j][0]<a[i][j][0]){
                            a[i][j][0]=a[i][k][0]+a[k][j][0];
                            a[i][j][1]=a[i][k][1]*a[k][j][1];
                        }
                        else if(a[i][k][0]+a[k][j][0]==a[i][j][0]){
                            a[i][j][1]+=a[i][k][1]*a[k][j][1];
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(a[i][j][1]==2) ans++;
                }
            }
            cout<<ans/2<<'\n';
        }
        else if(f){
            if(d<=c){
                cout<<"0\n";
                continue;
            }
            long long num=d/c;
            num=num*2-1;
            cout<<((n-num>0)?n-num:0)<<'\n';
        }
    }
    return 0;
}
