#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N],s[N];
int l=1,r,ans;
bool check(int mid){
    for(int r=mid;r<=n;r++){
        if(1ll*mid*a[r]-s[r]+s[r-mid]<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    r=n;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
