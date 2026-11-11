#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,s;
long long a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    s/=n;
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            b[i]+=a[i]-a[j];
        }
    }
    for(int i=n;i>=1;i--){
        if(b[i]<=m){
            cout<<i;
            break;
        }
    }
    return 0;
}
