#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[111111],c=0,mi=0x3f3f3f3f,t=0,b[111111],sum=0;
    cin >> n >> m;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
        c+=a[i];
    }
    for(long long i=1;i<=n;i++){
        if(abs(a[i]*n-c)<mi){
            mi=abs(a[i]*n-c);
            t=a[i];
        }
    }
    for(long long i=1;i<=n;i++){
        b[i]=abs(t-a[i]);
    }
    sort(b+1,b+n+1);
    for(long long i=1;i<=n;i++){
        sum+=b[i];
        if(sum>m){
            cout << i-1;
            return 0;
        }
    }
    return 0;
}
