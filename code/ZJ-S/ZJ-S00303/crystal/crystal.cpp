#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
int n,ans;
ll m,a[500003],sum[500003];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++)sum[i] = sum[i-1]+a[i];
    for(int i = 1,j = 1;i<=n;i++){
        while(j<=i && 1ll*a[i]*(i-j+1)-(sum[i]-sum[j-1])>m)j++;
        ans = max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
/*
g++ -o crystal/crystal crystal/crystal.cpp -O2 -std=c++14 -static -Wall -Wshadow
*/