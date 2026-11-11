#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,a[10101],t=1,s=0;
string b[10101];
cin>>n;
if(n!=2)
{
    cout<<"0";
}
for(int i=1;i<=n;i++)
{
    cin>>a[i]>>b[i];
    if(i==2)
    {
        t=a[i-1];
        if(a[i]<t)

        {
            t=a[i];
        }
        cout<<t;
    }
}
return 0;
}
