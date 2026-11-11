#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],b[N],c[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        b[i]+=b[i-1];
        b[i]+=(a[i]-a[i-1])*i;
    }
    cout<<lower_bound(b,b+n,m)-b;
    return 0;
}