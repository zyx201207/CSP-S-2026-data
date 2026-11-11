#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,m,a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    a[0]=-1;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            a[++cnt]=a[i];
        }
    }
    cout<<a[n-m+1];
    return 0;
}
