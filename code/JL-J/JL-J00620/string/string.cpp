#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++)
        {
            s+=c;
        }
    }
    string s1=s;
    reverse(s1.begin(),s1.end());
    int ss=s.size();
    if(s==s1)
    {
        cout<<'0';
        return 0;
    }
    else
    {
        for(int i=0;i<ss;i++,ss--)
        {
            if(s[i]!=s[ss])
            {
                s[ss]=s[i];
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
