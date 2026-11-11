#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
int ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    for(int i=2;i<=n;i++){
        int l=1,r=i-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid)-(s[i-1]-s[mid-1])>m) l=mid+1;
            else r=mid;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
//g++ crystal.cpp -o crystal -std=c++11