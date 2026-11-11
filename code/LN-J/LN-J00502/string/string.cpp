#include <bits/stdc++.h>
using namespace std;
string s;
long long ans;


int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    long long p=0;
    for(int i = 0;i<a;i++)
    {
        long long b;
        char c;
        cin>>b>>c;
        for(int j = 0;j<b;j++)
        {
            s+=c;
        }
        p+=b;
    }
    for(long long i = 0;i<(p+1)/2;i++)
    {
        if(s[i]!=s[p-i-1])ans++;

    }
    cout<<ans;
}
