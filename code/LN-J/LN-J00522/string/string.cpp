#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++)
        {
            s+=c;
        }
    }
    for(int i=0;i<(s.size()+1)/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
