#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="#";
    for(int i=1;i<=n;i++)
    {
        int m;
        char a;
        cin>>m>>a;
        for(int j=1;j<=m;j++)
        {
            s=s+a;
        }
    }
    int ans=0;
    for(int i=1;i<=(s.size()-1)/2;i++)
    {
        if(s[i]!=s[s.size()-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
