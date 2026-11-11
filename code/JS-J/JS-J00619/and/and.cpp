#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,t;
    cin>>n,m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        b[i]=a[i]&a[i+1];
    }for(int i=1;i<=n-1;i++){
        t=max(b[i],b[i+1]);
    }cout<<t;
    return 0;
}
