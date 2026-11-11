#include<bits/stdc++.h>
using namespace std;
long long dy[2000006],zbc[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--){
        long long n,d,ans=0;
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>dy[i];
            zbc[i]=dy[i]-dy[i-1];
        }
        for(long long i=4;i<=n;i++){
            if(zbc[i-3]+zbc[i-2]<=d&&zbc[i-1]+zbc[i-2]<=d&&zbc[i-1]+zbc[i-2]+zbc[i-3]>d)ans++;
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
}
