#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    long long a[10005];
    string b[10005];
    string s;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
        for(int i=1;i<=a[i];i++)
        {
            s+=b[i];
        }
    }
    long long len=s.size();
    for(int i=0;i<len;i++)
    {
            if(i==len-1-i) return 0;
            if(s[i]!=s[len-1-i]) cnt++;

    }

    cout<<cnt;
    return 0;
}
