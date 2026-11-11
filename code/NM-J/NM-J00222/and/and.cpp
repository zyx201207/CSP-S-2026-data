#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,ans1;
long long a[100000086];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=a[i]&a[i+1];
    }
    sort(a+1,a+1+n);
    ans1=a[n-2]&a[n-1];
    if(m==1) cout<<a[n];
    else if(m==n) cout<<ans;
    else cout<<ans1;
    return 0;
}
