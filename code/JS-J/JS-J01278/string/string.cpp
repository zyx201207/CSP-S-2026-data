#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,char> pic;
int n;
pic a[200005];
ll cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    int l = 1,r = n;
    while(l < r)
    {
        if(a[l].first > a[r].first)
        {
            if(a[l].second != a[r].second)
                cnt += a[r].first;
            a[l].first -= a[r].first;
            r--;
        }
        else if(a[l].first < a[r].first)
        {
            if(a[l].second != a[r].second)
                cnt += a[l].first;
            a[r].first -= a[l].first;
            l++;
        }
        else
        {
            if(a[l].second != a[r].second)
                cnt += a[l].first;
            l++;
            r--;
        }
    }
    cout << cnt ;
    return 0;
}
