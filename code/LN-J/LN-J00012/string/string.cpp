#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        char c;
        cin>>c;
        for(int j=1;j<=x;j++)
        {
            s+=c;
        }
    }
    int ans=0;
    for(int i=0;i<=(s.size())/2;i++)
    {
        int j=s.size()-1-i;
        if(s[i]!=s[j])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
//tmz
