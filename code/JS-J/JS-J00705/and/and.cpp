#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1,greater<long long>());
        cout<<a[1]<<endl;
        return 0;
    }
    else if(m==2){
        sort(a+1,a+n+1,greater<long long>());
        cout<<(a[1]&a[2])<<endl;
        return 0;
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=m;i++){
            ans=ans&a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    else {
        sort(a+1,a+n+1,greater<long long>());
        ans=a[1];
        for(int i=2;i<=m;i++){
            ans=ans&a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    ans=a[n];
    for(int i=n-1;i>=n-m+1;i--){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
