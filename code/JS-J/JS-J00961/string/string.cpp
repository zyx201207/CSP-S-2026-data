#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
long long sum=0;
long long ans=0;
struct zone
{
    long long len;
    char ch;
}Z[N];
void research(long long L)
{
    int l=1,r=n;
    while(L>Z[l].len || L>Z[r].len)
    {
        long long d=min(Z[l].len,Z[r].len);
        if(Z[l].ch!=Z[r].ch)ans+=d;
        Z[l].len-=d;
        Z[r].len-=d;
        L-=d;
        if(Z[l].len==0)l++;
        if(Z[r].len==0)r--;

    }
    if(Z[l].ch!=Z[r].ch)ans+=L;
    return;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> Z[i].len >> Z[i].ch;
        sum+=Z[i].len;
    }
    research(sum/2);
    cout << ans;
    return 0;
}
