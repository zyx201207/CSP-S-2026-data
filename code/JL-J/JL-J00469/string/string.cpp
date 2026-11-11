#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n;
int a[200005];
string c[200005];
string s;
string s_left;
string s_right;
long long sumn = 0;
int cnt = 0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1; i<=n; i++)
    {
        cin>>a[i]>>c[i];
        sumn += a[i];
    }
    for(long long i=1; i<=sumn; i++)
    {
        for(long long j=1; j<=a[i]; j++)
        {
            s+=c[i];
        }
    }
    if(sumn % 2 == 0)
    {
        for(long long i=floor(1.0*s.size()/2)-1; i>=0; i--)
        {
            s_left += s[i];
        }
        for(long long i=ceil(1.0*s.size()/2); i<s.size(); i++)
        {
            s_right += s[i];
        }
        if(s_left == s_right) cout<<0;
        else
        {
            for(long long i=0; i<=s.size()/2; i++)
            {
                if(s_left[i] != s_right[i]) cnt++;
            }
        }
    }
    else if(sumn % 2 != 0)
    {
        for(long long i=floor(1.0*s.size()/2)-1; i>=0; i--)
        {
            s_left += s[i];
        }
        for(long long i=ceil(1.0*s.size()/2); i<s.size(); i++)
        {
            s_right += s[i];
        }
        if(s_left == s_right)
        {
            cout<<0;
            return 0;
        }
        else
        {
            for(long long i=0; i<=s.size()/2; i++)
            {
                if(s_left[i] != s_right[i])
                {
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
