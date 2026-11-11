/*
CSP-J 2026 T3
Author:DFLJ

Passed at 09:11
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> t[33];
int n,m,idx,ans,cnt[33];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        t[idx].push_back(x);
    }
    for(int i=31; i>=0; i--)
    {
        int val=(1<<i);
        for(auto j : t[idx])
        {
            if(j&val) cnt[i]++;
        }
        if(cnt[i]>=m)
        {
            for(auto j : t[idx])
            {
                if(j&val) t[idx+1].push_back(j);
            }
            idx++;
            ans+=val;
        }
    }
    cout<<ans;
    return 0;
}