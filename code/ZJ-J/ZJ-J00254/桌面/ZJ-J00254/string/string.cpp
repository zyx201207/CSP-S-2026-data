#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<char> c(n+1);
    string s=" ";
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
        for(int j=1;j<=a[i];++j)
        {
            s+=c[i];
        }
    }
    int ans=0;
    int mid=(sum-1)/2+1;
    for(int i=1;i<=mid;++i)
    {
        if(s[i]!=s[sum+1-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}