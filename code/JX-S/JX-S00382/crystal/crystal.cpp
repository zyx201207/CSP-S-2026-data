#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long a[500010];
long long f[500010];
long long cnt;
long long x;
long long ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        f[i]=(i-1)*(a[i]-a[i-1])+f[i-1];
    }
    for(long long i=1;i<=n;i++){
        if(f[i]<=m){
            ans=max(ans,i);
        }
        else{
            x=0;
            for(long long j=cnt;j<=i;j++){
                x=x+(a[i]-a[j]);
                if(f[i]-x<=m){
                    cnt=j;
                    ans=max(ans,i-j);
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
