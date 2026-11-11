#include<bits/stdc++.h>
using namespace std;
long long cnt;
long long n,a[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char b[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n/2;i++){
        if(a[i]==a[n-i+1]&&b[i]!=b[n-i+1]) cnt+=a[i];
        if(a[i]!=a[n-i+1]&&b[i]!=b[n-i+1]) cnt+=abs(a[i]-a[n-i+1]);
    }
    cout<<cnt;
    return 0;
}
