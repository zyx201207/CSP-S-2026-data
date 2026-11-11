#include <bits/stdc++.h>
using namespace std;
string s;
int a[10000],n,len;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c;
        for(int j=len;j<len+a[i];j++)
        {
            s[j]=c;
        }
        len=len+a[i];
    }
    cout<<0;
}
