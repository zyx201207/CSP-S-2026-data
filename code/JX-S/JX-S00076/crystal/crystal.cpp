#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
bool f1=1;
bool f2=1;
bool f3=1;
long long h;
bool f(int x){
    long long t=0;
    for(int i=x;i<=n;i++){
        for(int j=x-1;j>=1;j--){
            t+=(a[i]-a[j]);
            if(t>m){
                return 0;
            }
        }
        return 1;
        t=0;
    }
}
int k[205];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(abs(a[i])>100){
            f1=0;
        }
        if(a[i]!=i){
            f2=0;
        }
        if(f3 && i!=1 && i!=n){
            if(a[i]-a[i-1]!=a[i+1]-a[i]){
                f3=0;
            }
        }
    }
    if(f2){
        long long d=m;
        for(int i=1;i<=n;i++){
            if(m-i+1>=0){
                m-=(i-1);
            }
            else{
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    if(f3){
        h=a[2]-a[1];
        long long d=m;
        for(int i=1;i<=n;i++){
            if(m-(1ll*(i-1)*h)>=0){
                m-=(1ll*(i-1)*h);
            }
            else{
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }
    if(f1){
        int ans=0;
        for(int i=1;i<=n;i++){
            k[a[i]+100]++;
        }
        for(int i=200;i>=0;i--){
            long long sum=m;
            int cnt=k[i];
            for(int j=i-1;j>=0;j--){
                if(sum-(1ll*(i-j)*k[j])>=0){
                    sum-=(1ll*(i-j)*k[j]);
                    cnt+=k[j];
                }
                else{
                    cnt+=(sum/(i-j));
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    int l=1,r=n,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(f(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
