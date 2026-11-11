#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long c[500005];
long long n,m;
bool check(long long j,long long h){
    if(j*(j+1)<=m*h) return 1;
    else return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>> n >> m;
    for(long long i=1;i<=n;i++) cin>> a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<n;i++) c[i]=a[i+1]-a[i];
    bool b=1;
    for(long long i=1;i<n;i++){
        if(c[i]!=c[i+1]){
            b=0;
            break;
        }
    }
    if(b==1){
        long long k=abs(a[2]-a[1]);
        long long l=1,r=1000000000;
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(mid,k)) l=mid+1;
            else r=mid-1;
        }
        cout<< l+1;
    }
    else{
        long long ans=0;
        for(long long i=1;i<=n;i++){
            long long q=a[i],p=m;
            long long cnt=1;
            for(long long j=i-1;j>=1;j--){
                if(p>=q-a[j]){
                    cnt++;
                    p-=(q-a[j]);
                }
                else break;
            }
            ans=max(ans,cnt);
        }
        cout<< ans;
    }
    return 0;
}
