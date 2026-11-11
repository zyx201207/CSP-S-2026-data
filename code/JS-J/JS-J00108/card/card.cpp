#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen('card.in','r',stdin);
    freopen('card.out','w',stdout);
    int n,m;
    cin>>n>>m;
    string s;
    char a[300005];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        s='0';
        for(int j=i;j<=n;j++)
        {
            for(int k=0;k<s.length();k++)
            {
                if(a[j]==s[k])
                {
                    for(int p=k;p<s.length();p++)
                    {

                    }
                }
                s+=a[j];
            }
        }
    }
}
