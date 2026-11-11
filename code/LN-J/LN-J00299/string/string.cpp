#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    long long n;
    cin>>n;
    long long x;
    char y;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        for(int j=1;j<=x;j++)
        {
            s+=y;
        }
    }
    long long ans=0;
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            ans++;
        }
    }
    cout<<ans;

}
