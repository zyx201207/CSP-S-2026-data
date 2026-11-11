#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)s+=c;
    }
    long long ans=0;
    for(int i=0;i<s.size()/2;i++)
    {
        ans+=s[i]!=s[s.size()-i-1];
    }
    cout<<ans;
return 0;
}
/*++rp*/
