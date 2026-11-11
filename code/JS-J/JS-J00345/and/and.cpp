#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans = -1;
int* a;
bool* used;
void f(int depth,int v,int s)
{
    if(depth == m)
    {
        ans = max(ans,v);
        return ;
    }
    for(int i = s;i <= n;i++)
    {
        if(used[i]) continue;
        used[i] = 1;
        if(depth == 0) f(depth + 1,a[i],s + 1);
        else f(depth + 1,v & a[i],s + 1);
        used[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    a = new int[n + 1];
    used = new bool[n + 1]();
    for(int i = 1;i <= n;i++) cin >> a[i];
    f(0,0,1);
    cout << ans;
    return 0;
}
