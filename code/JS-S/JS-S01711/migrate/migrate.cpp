#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d,ans=0;
        long long x[50100];
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        sort(x+1,x+n+1);
        for(int i=1;i<=n;i++){
            long long f[50100][3];
            for(int j=i;j<=n;j++){
                f[j][1]=0;
                f[j][2]=10000000;
            }
            f[i][1]=1;
            f[i][2]=0;
            for(int j=i;j<=n;j++){
                for(int k=1;j+k<=n;k++){
                    if(x[j+k]>x[j]+d){
                        break;
                    }
                    if(f[j][2]+1<f[j+k][2]){
                        f[j+k][1]=1;
                        f[j+k][2]=f[j][2]+1;
                    }else if(f[j][2]+1==f[j+k][2]){
                        f[j+k][1]++;
                    }
                }
                if(f[j][1]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
