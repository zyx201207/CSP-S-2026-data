#include<bits/stdc++.h>
using namespace std;
int n,a[200010],l,mina,z,c;
char b[200010];
string s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        l+=a[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=b[i];
        }
    }
    z=(l+1)/2;
    c=l-z;
    for(int i=1;i<=c;i++)
    {
        if(s[z-i-1]!=s[z+i-1])
        {
            s[z+i]=s[z-i];
            mina++;
        }
    }
    cout<<mina;
    return 0;
}
