#include <bits/stdc++.h>
using namespace std;
string s;
int ans = 0;
int wsd(string s1,string s2)
{
    int sum1 = 0,sum2 = 0;
    int l = 0;
    if(s1.size()%2 != 0)
    {
        l = (s1.size()+1)/2;
        if(s1[l] != s2[l])
        {
            sum1++;
            sum2++;
        }
        for(int i = 0;i < l;i++)
        {
            if(s1[i] != s2[i])
            {

                sum1++;
            }
        }
        for(int i = l+1;i <= s.size();i++)
        {
            if(s1[i] != s2[i])
            {

                sum2++;
            }
        }
        return min(sum1,sum2);
    }
    else{
        l = s1.size()/2;
        for(int i = 0;i < l;i++)
        {
            if(s1[i] != s2[i])
            {

                sum1++;
            }
        }
        for(int i = l;i <= s.size();i++)
        {
            if(s1[i] != s2[i])
            {

                sum2++;
            }
        }
        return min(sum1,sum2);
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        int a;cin>>a;
        string l;
        cin>>l;
        for(int j = 1;j <= a;j++)
        {
            s += l;
        }
    }
    string fs = "";
    for(int i = s.size()-1;i >= 0;i--)
    {

        fs += s[i];
    }

    if(s == fs)
    {
        cout<<0;
    }
    ans = wsd(s,fs);
    cout<<ans;
    return 0;
}
