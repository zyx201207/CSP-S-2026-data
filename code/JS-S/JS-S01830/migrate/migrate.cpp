#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long f(long long z,long long j,long long cnt,long long b,long long d){
    long long ans=0;
    if(a[j]-a[z]>d*(cnt-b)){
        return 0;
    }
    if(z==j&&b==cnt){
        return 1;
    }
    for(long long k=z;k<=j&&a[k]-a[z]<=d;k++){
        ans+=f(k,j,cnt,b+1,d);
    }
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
    long long n=0,d=0,ans=0;
    cin>>n>>d;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
                long long v=i,cnt=1;
            for(long long k=i;k<=j;k++){
                if(a[k]-a[v]>d){
                        v=k-1;
                    cnt++;
                }
            }
            long long r=f(i,j,cnt,0,d);
            if(r==2){
                    //cout<<cnt<<" "<<i<<" "<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        a[i]=0;
    }
}
return 0;
}
