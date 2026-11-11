#include<bits/stdc++.h>
using namespace std;
long long a[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long ad=0;
    long long pd1=0,pd2=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            pd1=1;
        }
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    ad=a[2]-a[1];
    for(long long i=3;i<=n;i++){
        if(ad!=a[3]-a[2]){
            pd2=1;
        }
    }
    if(pd1==0){
        long long sum=0;
        for(long long i=1;i<=n;i++){
            sum+=i;
            if(sum>m){
                cout<<i;
                return 0;
            }
        }
    }
    else if(pd2==0){
        long long sum=0;
        m=m/ad;
        for(long long i=1;i<=n;i++){
            sum+=i;
            if(sum>m){
                cout<<i;
                return 0;
            }
        }
    }
    else{
        sort(a+1,a+n+1);
        long long maxn=1;
        for(long long i=1;i<=n;i++){
            long long sum=0,cnt=1;
            for(long long j=i-1;j>=1;j--){
                sum=sum+(a[i]-a[j]);
                if(sum>m){
                    maxn=max(maxn,cnt);
                    break;
                }
                else{
                    cnt++;
                }
            }
            maxn=max(maxn,cnt);
        }
        cout<<maxn;
    }
    return 0;
}
