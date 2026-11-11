#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int n,m,x,sum,ans;
int a[MAXN];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int l=1;
    for(int r=1;r<=n;r++){
        sum+=(r-l)*(a[r]-a[r-1]);
        while(sum>m){
            sum-=a[r]-a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
//g++ crystal.cpp -o crystal -std=c++14 -O2 -static -Wall -Wextra -Wshadow
//ulimit -v 1048576
//ulimit -s 1048576
//time ./crystal








