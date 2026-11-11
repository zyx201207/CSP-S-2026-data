#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n,m;
long long a[N];
long long cf[N],sum[N];
bool A=1,B=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    long long c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            A=0;
        }
        if(i==2){
            c=a[2]-a[1];
        }else if(i>2){
            if(a[i]-a[i-1]!=c){
                B=0;
            }
        }
    }
    sort(a+1,a+n+1);
    if(A){
        long long ans=n;
        for(long long i=1;i<=n;i++){
            if(i*(i-1)/2>m){
                ans=i-1;
            }
        }
        cout<<ans;
        return 0;
    }else if(B){
        long long ans=n;
        for(long long i=1;i<=n;i++){
            if(c*i*(i-1)/2>m){
                ans=i-1;
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cf[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+cf[i]*i;
    }
    for(int i=n;i>=2;i--){
        sum[i]=sum[i-1];
    }
    sum[1]=0;
    int l=1,r=n;
    long long mid;
    while(l<r){
        mid=l+((r-l+1)/2);
        bool ok=0;
        for(long long i=mid;i<=n;i++){
            if(sum[i]-sum[i-mid+1]-(i-mid)*(a[i]-a[i-mid+1])<=m){
                ok=1;
                break;
            }
        }
        if(ok){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
