#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long q[500005];
long long n,m;
int er(int x){
    int l=1;
    int r=x;
    int an=x;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[x]*abs(r-l)-q[x-1]-q[l-1]>m){
            l=mid+1;
        }
        else{
            r=mid-1;
            an=mid;
        }
    }
    return an;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=1e12;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        q[i]=q[i-1]+a[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=max(ans,i-er(i)+1);
    }
    cout<<ans;
    return 0;
}
