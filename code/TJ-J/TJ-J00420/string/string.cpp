#include<bits/stdc++.h>
using namespace std;
string s;
int a=0;
int b,n;

char o;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b>>o;
        a+=b;
    }
    a/=2;
    cout<<a;
    return 0;
}
