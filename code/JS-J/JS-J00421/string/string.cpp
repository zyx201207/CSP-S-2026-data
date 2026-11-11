#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
pair<ll,char> q[N];
ll ans = 0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);    cout.tie(0);

    cin>>n;
    for(int i = 1;i <= n;i++) cin>>q[i].first>>q[i].second;

    int l = 0,r = n + 1;
    ll sum1 = 0,sum2 = 0;
    while(1){
        if(sum1 > sum2){
            r--;
            sum2 += q[r].first;
        }
        else if(sum1 < sum2){
            l++;
            sum1 += q[l].first;
        }
        else{
            l++;    r--;
            sum1 += q[l].first;
            sum2 += q[r].first;
        }
        if(l >= r) break;

        if(q[l].second != q[r].second){
            if(sum1 <= sum2)
                ans += min(sum1 - sum2 + q[r].first,q[l].first);
            else
                ans += min(sum2 - sum1 + q[l].first,q[r].first);
        }
    }
    cout<<ans;
    return 0;
}
