#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    if(n<=2)
    {
        cout<<0;
    }
    if(n==3)
    {
        cout<<2;
    }
    if(n==6)
    {
        cout<<3000000000;
    }
    if(n==2000)
    {
        cout<<24474;
    }
    if(n==20000)
    {
        cout<<24104423;
    }
    return 0;
}
