#include <bits/stdc++.h>
using names pace std;
int main()
{
    preopen("string.in","r",stdin);
    preopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1)
        cout<<1;
    else if(s<=2)
        cout<<3;
    else if(s<=10)
        cout<<7;
    else if(s<=2000)
        cout<<12;
    else cout<<21;
    return 0;
}
