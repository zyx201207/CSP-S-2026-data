#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> q,q1;
long long n,k,ans,a[100005],ans2,ans1;
bool cmp(long long x,long long y)
{
    return x > y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        if(a[i] % 2 == 0)
        {
            q.push(a[i]);
        }
        else
        {
            q1.push(a[i]);
        }
    }
    sort(a + 1,a + 1 + n,cmp);
    ans = a[1];
    for(int i = 2;i <= k;i ++)
    {
        ans &= a[i];
    }
    ans1 = q.top();
    ans2 = ans1;
    q.pop();
    for(int i = 2;i <= k && q.size();i ++)
    {
        ans1 &= q.top();
        if(i % 2 == 0)
            ans2 &= q.top();
        q.pop();
    }
    ans = max(ans,ans1);
    ans1 = q1.top();
    q1.pop();
    for(int i = 2;i <= k && q1.size();i ++)
    {
        ans1 &= q1.top();
        if(i % 2 == 0)
            ans2 &= q.top();
        q1.pop();
    }
    ans = max(ans,ans1);
    ans = max(ans,ans2);
    cout << ans;
    return 0;
}
