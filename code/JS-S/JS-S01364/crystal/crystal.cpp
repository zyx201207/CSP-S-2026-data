#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N];
long long s[N];
bool check(long long mid){
    for(long long i=mid;i<=n;i++){
        long long dis=s[i]-s[i-mid];
        long long tmp=1ll*mid*a[i];
        if(tmp-dis<=m) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    long long l=0,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)==true){
            l=mid+1;
            ans=mid;
        }else r=mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}
