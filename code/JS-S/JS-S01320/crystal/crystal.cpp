#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll n,m,a[N],r = 1,cnt = 1,ans,sum;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    for(int l = 1; l<=n; l++)
    {
        while(r + 1 <= n && (1ll)*sum + (1ll) * cnt * (a[r + 1] - a[r]) <= m)
        {
            sum += (1ll)*cnt * (a[r + 1] - a[r]);
            r++;
            cnt++;
        }
        ans = max(ans,r - l + 1);
        sum -= (a[r] - a[l]);
        cnt--;
    }
    cout << ans;
}
