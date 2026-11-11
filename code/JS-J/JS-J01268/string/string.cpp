#include <bits/stdc++.h>
using namespace std;
int n,a[9999999];
string s;
char c[999999];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=a[i];j++)
        {
            cin>>c[i];
            cout<<c[i];
        }
    }
    if(n=1) cout<<0;
    return 0;
}
