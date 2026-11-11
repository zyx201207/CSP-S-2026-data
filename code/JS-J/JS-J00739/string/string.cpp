#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a;
    cin>>a;
    int s[a];
    int n[a]={0};
    int m=0;
    for(int i=0;i<a;i++)
    {
        cin>>s[i];
        string w;
        cin>>w;
    }
    int ans=0;
    for(int i=0;i<a;i++)
    {
        ans+=s[i];
    }
    ans/=2;
    cout<<ans;
    return 0;
}
