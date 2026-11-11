#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
string c[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    int w=s.length();
    for (int i=0;i<w/2;i++)
    {
        if (s[i]!=s[w-1-i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
