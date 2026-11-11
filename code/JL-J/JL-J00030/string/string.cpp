#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out""w",stdout);
    int n;
    cin>>n;
    int m;
    char c;
    string s;
    string a;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>m>>c;
        for(int i=1;i<=m;i++)
        {
            s+=c;
            a=s;
        }
    }
    reverse(a.begin(),a.end());
    if(a==s)
    {
        sum=0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(s[i]!=s[n-i+1])
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}

