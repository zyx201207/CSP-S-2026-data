#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
__int128 sum[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin >> n >> m;
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a,a+n);
    sum[0]=a[0];
    for(int i=1;i<n;++i) sum[i]=sum[i-1]+a[i];
    int j=0,ans=1;
    for(int i=0;i<n;++i){
        while(j<i && __int128(i-j+1)*a[i]-(sum[i]-(j==0?0:sum[j-1]))>m) ++j;
        ans=max(ans,i-j+1);
    }
    cout << ans << '\n';
    return 0;
}