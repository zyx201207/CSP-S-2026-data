#include<bits/stdc++.h>
#define int long long
#define L(i,k,n) for(int i = k;i <= n;i++)
#define R(i,n,k) for(int i = n;i >= k;i--)
#define pr pair<int,char>

using namespace std;



signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int t;
    cin>>t;
    string s;
    int n = 0;
    while(t--)
    {
        int len;
        string c;
        cin >> len>>c;
        L(i,1,len)
        {
            s+=c;
        }
        n+=len;
    }
    string ls,rs;
    if(n%2)
    {
        L(i,0,n/2-1)
        {
            ls += s[i];
        }
        L(i,n/2+1,n-1)
        {
            rs+= s[i];
        }
    }
//    cout<<ls<<' '<<rs;
    reverse(rs.begin(),rs.end());
    int ans =0;
    for(int i = 0;i < n/2;i++)
    {
        if(rs[i] != ls[i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
