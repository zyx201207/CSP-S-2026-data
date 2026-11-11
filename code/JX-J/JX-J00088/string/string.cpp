#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt = 0;
    cin>>n;
    int a[200005];
    char c1[200005];
    char c;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i]>>c;
        c1[i] = c;
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=a[i];j++)
        {
            s = s+c1[i];
        }
    }
    for(int i = n;i>0;i--)
    {
        for(int j = 1;j<=a[i];j++)
        {
            s1 = s1+c1[i];
        }
    }s
    int abx = s.length();
    for(int i = 1;i<=s.length()/2;i++)
    {
        if(s[i] == s1[abx]) continue;
        else cnt++;
    }
    cout<<cnt;
    return 0;
}
