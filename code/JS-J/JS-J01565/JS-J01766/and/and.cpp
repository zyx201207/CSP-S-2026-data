#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    long long a[200005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans=a[n-1];
    if(m==1){
        cout<<ans;
        return 0;
    }
    for(int i=n-2;i>=n-m;i--){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}