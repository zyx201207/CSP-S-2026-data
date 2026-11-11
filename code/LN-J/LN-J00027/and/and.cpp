#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            s=max(s,(a[i]&a[j]));
        }
    }
    cout<<s;
    return 0;
}


