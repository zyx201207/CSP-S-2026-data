#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[676767],b,c;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        c=max(c,a[i]);
        b=max(b,a[i]);
        if(c==b)
        {
            c=a[i-1];
        }
    }
    int d=min(b,c);
    cout<<d;
}
