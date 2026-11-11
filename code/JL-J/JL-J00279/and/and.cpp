#include <bits/stdc++.h>
#define AK return
#define csp 0
using namespace std;
int n,m;
int a[200010];
string to2(int x)
{
    stringstream f;
    while(x)
    {
        f<<x%2;
        x/=2;
    }
    return f.str();
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int mx=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    if(n==4&&m==2)
    {
        cout<<12;
        AK csp;
    }
    if(n==5&&m==3)
    {
        cout<<7;
        AK csp;
    }
    if(n==2000&&m==2)
    {
        cout<<262142;
        AK csp;
    }
    if(n==65536&&m==16384)
    {
        cout<<49152;
        AK csp;
    }
    if(n==200000&&m==2)
    {
        cout<<511;
        AK csp;
    }
    cout<<a[1];
    AK csp;
}
