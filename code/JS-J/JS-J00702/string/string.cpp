#include <bits/stdc++.h>
using namespace std;
int n;
string s="";
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x;
        char c;
        cin>>x>>c;
        while(x--) s+=c;
    }
    int len=s.size();
    for(int i=0;i<=len/2-1;i++)
    {
        if(s[i]!=s[len-i-1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
