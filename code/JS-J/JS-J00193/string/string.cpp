#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
            s+=c;
    }
    int l=0,r=(int)s.size()-1,ans=0;
    while(l<=r)
    {
        if(s[l]!=s[r]) ans++;
        l++;r--;
    }
    cout<<ans<<'\n';
    return 0;
}