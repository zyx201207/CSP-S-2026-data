#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005],ma=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+2);
    for(long long i=1;i<=n;i++){
        long long k=m,h=1;
        for(long long j=i-1;j>=1;j--){
            if(k>=a[i]-a[j]){
                h++;
                k=k-(a[i]-a[j]);
            }else break;
        }
        ma=max(ma,h);
    }
    cout<<ma;
    return 0;
}
