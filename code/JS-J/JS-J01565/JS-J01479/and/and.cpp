#include<bits/stdc++.h>
using namespace std;
int cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200005];
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long ans=a[1];
    for(long long i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
