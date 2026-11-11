#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

//main
long long f[N],q[N];
long long m;
int n;
//

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i<=n;i++) cin >> f[i];
    sort(f+1,f+n+1);
    for(int i = 1;i<=n;i++) q[i] = q[i-1]+f[i];
    int an = 0;
    for(int i = 1;i<=n;i++)
    {
        int l = 1,r = i;
        while(l < r)
        {
            int mid = l+r >> 1;
            if(f[i]*(i-mid+1)-q[i]+q[mid-1] <= m)   r = mid;
            else    l = mid+1;
        }
        an = max(an,i-l+1);
    }
    cout << an;
    return 0;
}