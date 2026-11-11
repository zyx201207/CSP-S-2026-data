#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>5000){
        long long u=a[2]-a[1];
        for(int i=1;i<n;i++,u+=u){
            if(m-u){
                m-=u;
            }
            else{
                cout<<i;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long summ=0;
    long long p=0,maxn=0;
    for(long long i=n;i>=1;i--){
        summ=a[i]*i;
        if(summ-sum[i]<=m){
            maxn=max(i-1,maxn);

        }
    }
    cout<<maxn+1;
}
