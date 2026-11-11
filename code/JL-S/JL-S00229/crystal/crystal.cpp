#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum=0,b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        b[i]=a[i+1]-a[i];
    }
    sort(b+1,b+n);
    for(int i=1;i<=n-1;i++){
        sum+=b[i]*i;
        if(sum>m){
            cout<<i;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
