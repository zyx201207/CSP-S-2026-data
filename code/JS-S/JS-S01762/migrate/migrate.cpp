#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
long long t[5005][5005];
long long c,k;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>> c >> k;
    for(long long i=1;i<=k;i++){
        long long n,d; cin>> n >> d;
        long long ans=0;
        for(long long i=1;i<=n;i++) cin>> a[i];
        for(long long i=1;i<=n;i++){
            long long s=1;
            for(long long j=i+1;j<=n;j++){
                if(a[i]+s*d>=a[j]){
                    t[i][j]=s;
                }
                else{
                    if(a[j]-a[j-1]<=d){
                        s++;
                        t[i][j]=s;
                    }
                    else{
                        for(long long h=j;h<=n;h++) t[i][h]=0;
                        continue;
                    }
                }
            }
        }
        for(long long i=1;i<=n;i++){
            for(long long j=i;j<=n;j++){
                if(t[i][j]==t[i][j-1]+1 && t[i][j-1]==t[i][j-2] && t[i][j-2]==t[i][j-3]+1){
                    ans++;
                }
            }
        }
        cout<< ans << endl;
    }
    return 0;
}
