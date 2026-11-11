#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int  n,ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>a[i]>>c;
        for(int j=0;j<a[i];j++)
        {
            s[j]=c;
        }
    }
    for(int i=0;i<=s.size();i++)
    {
        if(s[i+1]==s[i])
            ans=-1;
    }
    if(ans==-1)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<=(s.size())/2+1;i++){
        if(s[i]!=s[s.size()-1-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
