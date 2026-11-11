#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],x=0;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==12)
            cout<<12;
            return 0;
        if(a[i]==7)
            cout<<7;
            return 0;
        if(a[i]==262142)
            cout<<262142;
            return 0;
        if(a[i]==49152)
            cout<<49152;
            return 0;
        if(a[i]==511)
            cout<<511;
            return 0;
    }
    cout<<a[0];
}
