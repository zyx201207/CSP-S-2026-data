#include<bits/stdc++.h>
using namespace std;
int a[200005],c[200005];
string s[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string b;
        cin>>a[i];
        c[i]=a[i];
        while(c[i])
        {
            s[i]=s[i]+char(c[i]%2+48);
            c[i]/=2;
        }
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    if(m==n)
        cout<<0;
    return 0;
}
