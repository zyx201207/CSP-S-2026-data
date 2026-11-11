#include <bits/stdc++.h>
using namespace std;
long long a[100005];
char c[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=s[s.length()-i+1])
        {
            s[s.length()-i+1]=s[i];
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
