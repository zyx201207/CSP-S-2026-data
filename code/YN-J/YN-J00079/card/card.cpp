#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
string s[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            if (s[i].find((char)(a[j]+'0'))==-1)
            {
                s[i]+=(char)(a[j]+'0');
            }
            else
            {
                s[i].erase(s[i].find((char)(a[j]+'0')),s[i].length()-s[i].find((char)(a[j]+'0'))+1);
                s[i]+=(char)(a[j]+'0');
            }
        }
    }
    for (int i=1;i<=m;i++)
    {
        long long cnt=0;
        for (int j=1;j<=n;j++)
        {
            cnt+=(s[j].find((char)(i+'0'))!=-1);
        }
        cout<<cnt<<" ";
    }
    return 0;
}
