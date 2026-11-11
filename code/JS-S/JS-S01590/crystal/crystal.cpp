#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long s[500005];
int ans;
bool check(int x){
   // cout<<x<<' ';
    long long h;
    for(int i=x;i<=n;i++){
        h=(x-1)*a[i]-(s[i-1]-s[i-x]);
        if(h<=k){
               // cout<<'\n';
            return 1;
        }
    }
  //  cout<<'\n';
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=2,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
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

