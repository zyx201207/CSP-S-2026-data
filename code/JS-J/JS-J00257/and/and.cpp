#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    long long n, m, t=0, maxb=0, p, nums, l;
    cin>>n>>m;
    string s[n], str;
    for (int i=0;i<n;i++)
    {
        l=0;
        str="";
        cin>>t;
        while (t != 0)
        {
            str+=char(t%2+'0');
            t/=2;
            l++;
        }
        maxb=max(maxb, l);
        s[i]=str;
    }
    p=pow(2, maxb);
    for (int i=maxb-1;i>=0;i--)
    {
        p/=2;nums=0;
        for (int j=0;j<n;j++) if (s[j].size()>i) if (s[j][i]=='1') nums++;
        if (nums<m) continue;
        t+=p;
        for (int j=0;j<n;j++) if (s[j].size()<i || s[j][i]=='0') s[j]="";
    }
    cout<<t;
    return 0;
}
