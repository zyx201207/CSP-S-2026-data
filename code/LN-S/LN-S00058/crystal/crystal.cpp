#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5+5;
long long n,m,ans,a[N],s[N],f[N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i = 1;i<=n;i++){
        s[i] = s[i-1]+(i-1)*(a[i]-a[i-1]);
        f[i] = f[i-1]+a[i];
    }
    long long l = 1;
    for(long long r = 1;r<=n;r++){
        while(s[r]-(a[r]*l-f[l])>m) l++;
        ans = max(ans,r-l);
    }
    cout<<ans<<endl;
    return 0;
}
/*
g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall -fsanitize=address,undefined
*/