#include <bits/stdc++.h>
using namespace std;
long long n,m,s,a[500005],ans,k,b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
        if(b[i]>m){
            cout<<i-1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
