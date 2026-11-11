#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],s[N];
int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal3.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    bool okA=1,okB=1;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=1)okA=0;
        if(a[i]-a[i-1]!=a[2]-a[1])okB=0;
        if(!(okA||okB))break;
    }
    //if(n<=5000){
    //    int ans=0;
    //    for(int i=0;i<=n;i++){
    //        for(int j=i+1;j<=n;j++){
    //            if(a[j]*(j-i)-(s[j]-s[i])<=m)ans=max(ans,j-i);
    //        }
    //    }
    //cout<<ans;
    //}else if(okA||okB){
    //    long long sum=0;
    //    int i=n;
    //    while(sum<=m&&i>=0){
    //        i--;
    //        sum=a[n]*(n-i)-(s[n]-s[i]);
    //    }
    //    if(sum<=m)cout<<n;
    //    else cout<<n-i;
    //}else{
        int L=1,R=2;
        long long x=m;
        int ans=0,lon=1;
        long long b[n+1];
        for(int i=1;i<=n;i++)b[i]=a[i];
        while(R<=n){
            if(b[R]-b[L]<=x){
                x-=(R-L)*(b[R]-b[L]);
                b[L]=b[R];
                lon++;
                ans=max(ans,lon);cout<<ans<<endl;
                for(int i=L;i<=R;i++){
                    cout<<b[i]<<" "<<a[i]<<endl;
                }
                R++;
            }else{
                x+=b[L]-a[L];
                L++;
                b[L]=b[R-1];
                lon--;
                if(L>R){
                    L--;
                    R++;
                }
            }
        }
        cout<<ans;
    //}
    return 0;
}
