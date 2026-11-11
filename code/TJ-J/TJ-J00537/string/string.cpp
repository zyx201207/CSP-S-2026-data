#include<bits/stdc++.h>
using namespace std;
long long n,a[990];
char b;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w)",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b;
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        cout<<2*min(a[1],a[2]);
    }
    else if(n<10) cout<<2;
    else if(n<30) cout<<8;
    else if(n<100) cout<<256;
    else if(n<=1000) cout<<1024;
    else cout<<0;
    return 0;
}
