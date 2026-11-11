#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005];
long long l;
string s;
int hw(string s)
{
    int cnt=0;
    for(int i=0;i*2<s.size();i++)
    {
        if(s[i]!=s[l-i-1])
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
        l+=a[i];
    }
    cout<<hw(s);

    return 0;
}
