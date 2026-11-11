#include<bits/stdc++.h>
using namespace std;
int n,nxt[500005],ans,ind = 1;
long long m,a[500005],s[500005];
bool check(int l,int r)
{
    if(a[r] * (r - l) - (s[r - 1] - s[l - 1]) <= m) return true;
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a + 1,a + n + 1);
    for(int i = n;i >= 1;i--)
    {
        if(a[i] != a[i + 1]) nxt[i] = i + 1;
        else nxt[i] = nxt[i + 1];
    }
    for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
    for(int i = 1;i <= n;i = nxt[i])
    {
        while(!check(ind,i) && ind < i) ind++;
        ans = max(ans,nxt[i] - ind);
    }
    cout<<ans;
    return 0;
}
