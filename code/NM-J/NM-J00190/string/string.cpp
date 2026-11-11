#include <bits/stdc++.h>
using namespace std;
map <string,int> s;
long long ans=0;
int main()
{
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a;
        int b;
        cin>>b>>a;
        s[a]=b;
    }
    int cnt=0;
    for(auto x:s)
    {
        cnt+=x.second;
    }
    for(auto x:s)
    {
        if(x.second>ans)
            ans=x.second;
    }
    cout<<ans;   
    return 0;
}