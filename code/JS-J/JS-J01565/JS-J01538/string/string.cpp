#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int ans;
    cin >>ans;
    while(ans--)
    {
        int a;
        char b;
        cin >>a>>b;
        for(int i=1;i<=a;i++)
        {
            s=s+b;
        }
    }
    int n=s.size();
    if(n%2!=0)
    {
        n=(n-1)/2;
    }
    else
    {
        n=n/2;
    }
    int t=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            t++;
        }
    }
    cout <<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
