#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,a[N];
long long sum;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        s[i]=s[i-1]+a[i];
    }
    long long ans;
    for(int i=1;i<=n;i++){

    }
    return 0;
}
