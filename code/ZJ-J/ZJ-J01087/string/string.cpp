#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s+=b;
        }
    }
    long long ans=0;
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-1])ans++;
    }
    cout<<ans;
}
