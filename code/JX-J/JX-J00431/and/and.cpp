#include <bits/stdc++.h>
using namespace std;
int a,b,s[111111];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for (int i=1;i<=a;i++)
    {

        cin>>s[i];
    }
    sort(s+1,s+a);
    cout<<s[a];
}
