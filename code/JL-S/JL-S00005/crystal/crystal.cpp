
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],c[500010],ans;
bool check(int x){
    int sum=0;
    for(int i=1;i<=x;i++){
        sum+=(a[x]-a[i]);
    }
    return sum<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    int mx=0;
    a[0]=a[1];
    for(int i=1;i<=n;i++){
        mx=max(mx,c[i]);
        if(a[i]!=a[i-1])flag=false;
    }
    if(m==0){
        cout<<mx;
        return 0;
    }
    if(flag==true){
        cout<<n;
        return 0;
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}

