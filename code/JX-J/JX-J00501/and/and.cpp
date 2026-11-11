#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=a[n];
    for(int i=n-1;i>n-m;i--){
        ans=(ans&a[i]);
    }
    cout<<ans;
    return 0;
}
