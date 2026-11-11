#include<bits/stdc++.h>
using namespace std;
int n,m,s[200010],a[200010],c_max;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        s[i]=a[i]&s[i-1];
    }
    for(int i=1;i<n-m+1;i++){
        int l=i+m;
        c_max=max(s[l-m]&s[i],c_max);
    }
    cout<<c_max;
    return 0;
}
