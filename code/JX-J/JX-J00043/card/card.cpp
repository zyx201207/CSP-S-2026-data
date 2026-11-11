#include<bits/stdc++.h>
using namespace std;
    int n,m;
    int maxn;
    char b[8];
string s(int x)
{
    for(int i=x;i>=0;i--)
    {
        int c=x%2;
        b[i]=c%2;

    }
    for(int i=x;i>=0;i--)
    {
        return b[i];
    }
}
int main()
{
    freopen(card.in,"r",stdin);
    freopen(card.out,"w",stdout);
    cin>>n>>m;
     char a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s(a[i]);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;i<=n+1;i++)
     {
         int s=a[i]|a[j];
         maxn=max(s,a[i+1]|a[j+1]);
     }
    }
    cout<<maxn;
    return 0;
}
