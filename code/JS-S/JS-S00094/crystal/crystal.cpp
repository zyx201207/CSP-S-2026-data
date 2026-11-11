#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 25;
int n,m;ll a[N];
ll sum[N];
int ans = 0;
//There's no problems like this on earth,you're only scared.
bool chk(int x,int av){
    return (av - x) * a[av] - sum[av - 1] + sum[x - 1] <= m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0);    cout.tie(0);

    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];

    for(int i = 1;i <= n;i++){
        int l = 0,r = i;
        while(l < r - 1){
            int mid = (l + r) / 2;
            if(chk(mid,i)){
                r = mid;
                ans = max(ans,i - mid + 1);
            }
            else l = mid;
        }
    }

    cout<<ans;
    return 0;
}
