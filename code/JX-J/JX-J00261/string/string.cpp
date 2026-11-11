#include<bits/stdc++.h>
using namespace std;
long long t,n,r,l,ans;
string s;
char a;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>a;
        for(int i=1;i<=n;i++) s+=a;
    }
    r=s.size()-1;
    while(r!=l||l<r)
    {
        if(s[r]!=s[l]) ans++;
        r--;
        l++;
    }
    cout<<ans;
    return 0;
}
