#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    string s;
    cin>>n>>m;
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    else if(m==2)
    {
        int c1=0,c2=0;
        for(int i=1;i<=n;i++)
        {
            if(i%2!=0)c1++;
            if(i%2==0)c2++;
            cout<<c1<<' '<<c2;
            return 0;
        }
    }

    else
    {
        int c=s.size();
        for(int i=1;i<=n;i++)
        {
            a[c]++;
            c++;
            if(c==n)c=1;
        }
        for(int i=1;i<s.size();i++)
        {
            if(a[i]!=0)
            {
                cout<<a[i]<<' ';
            }
        }
    }
    return 0;
}
