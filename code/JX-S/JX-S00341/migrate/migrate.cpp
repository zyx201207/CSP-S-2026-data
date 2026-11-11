#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","W",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long cnt=0;
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
        if(i!=1){
            cnt=abs(1ll*(i-1)*a[i]-s[i-1]);
            if(cnt>m){
                cout<<i-1;
                return 0;
            }
        }
    }
    cout<<n;
    return 0;
}
