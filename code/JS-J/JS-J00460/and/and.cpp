#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[100005],ans;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(long long i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
