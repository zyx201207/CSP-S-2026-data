#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s="";
    long long ans=0;



    for(int i=1; i<=n; i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=0; j<a; j++)
        {
            s+=c;
        }
    }

    for(int i=0; i<s.size()/2; i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
