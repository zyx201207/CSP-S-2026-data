#include <bits/stdc++.h>
using namespace std;
int sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n,a;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        int a;
        cin >>a;
        string b;
        cin >> b;
        for(int j = 1;j<=a;j++)
        {
            s+=b;
        }
    }
    for(int i = 0;i<=s.length()/2+1;i++)
    {
        if(s[i]!=s[s.length()-i-1])
        {
            sum++;
        }
    }
    cout <<sum;
    return 0;
}
