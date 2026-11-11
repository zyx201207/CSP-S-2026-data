#include <bits/stdc++.h>
using namespace std;
long long n,c[10005],sum;
string a[105];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        string q+=a[i];
    }
    for(int i=n-1;i>0;i--)
    {
        string s+=q[i];
    }
    for(int i=0;i<n;i++)
    {
        if(q[i]!=s[i])
        {
            sum++;
        }
    }
    cout<<sum/2;
    return 0;
}
