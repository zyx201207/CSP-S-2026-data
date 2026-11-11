#include<bits/stdc++.h>
using namespace std;
int a[1000000000];
char c[26];
char d[1000000000000000000];
char o[1000000000000000000];
bool w(char d)
{
    for(int i=m;i>0;i--)
    {
        for (int j=0;j<m;j++)
        {
            if(d[m]==d[i])
            {
                return true;
            }
            else
            {
                return fores;
            }
        }
    }
    
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    m=0;
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<a[j];i++)
        {
            d[i]=c[j];
            m++;
        }
    }
    if(w(d))
    for(int i=0;i<m;i++)
    {
        if(m%2!=0)
        {
            cout<<d[m/2+1];
        }
        else
        {
            cout<<d[m/2];
        }
    }
    return 0;
}
