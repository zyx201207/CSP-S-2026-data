#include<bits/stdc++.h>
using namespace std;
const int mxN=2e5+5;
int n,m;
long long int a[mxN],mx=LLONG_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(m==1) for(int i=1;i<=n;i++) mx=max(mx,a[i]);
    else if(m==2) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) mx=max(mx,(a[i]&a[j]));
    else if(m==3) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) mx=max(mx,(a[i]&a[j]&a[k]));
    else if(m==4) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int q=k+1;q<=n;q++) mx=max(mx,(a[i]&a[j]&a[k]&a[q]));
    else if(m==5) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++) for(int q=k+1;q<=n;q++) for(int p=q+1;p<=n;p++) mx=max(mx,(a[i]&a[j]&a[k]&a[q]&a[p]));
    cout<<mx;
    return 0;
}
