#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    long long ans = v[0];
    for (int i=1;i<m;i++)
    {
        ans &= v[i];
    }
    cout<<ans;
    return 0;
}

