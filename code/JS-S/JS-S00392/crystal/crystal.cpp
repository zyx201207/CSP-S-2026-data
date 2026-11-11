/*g++ crystal.cpp -o crystal -std=c++14 -Wall -Wextra -fsanitize=undefined,address*/
//g++ crystal.cpp -o crystal -std=c++14 -static -O2
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 5e5+10, mod = 998244353;
ll a[N], n, m, sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i-1] + a[i];
    int ans = 0;
    for(int i = n; i >= 1; i--){
        int l = 1, r = i;
        while(l < r){
            int mid = (l+r) >> 1;
            ll cnt = a[i] * (i-mid+1) - (sum[i] - sum[mid-1]);
            //cout<<"i="<<i<<" mid="<<mid<<" cnt="<<cnt<<endl;
            if(cnt <= m)r = mid;
            else l = mid + 1;
        }
        //cout<<"l:"<<l<<" r:"<<r<<endl;
        ans = max(ans, (i-l+1));
    }
    cout<<ans<<endl;
    return 0;
}