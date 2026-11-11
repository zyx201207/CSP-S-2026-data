#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],L,ans;
char b[1000000],s[1000000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=L+1;j<=L+1+a[i];j++)
        {
            s[j]=b[i];
        }
        L+=a[i];
    }
    for(int i=1;i<=(L+1)/2;i++)
    {
        if(s[i]!=s[L-i+1])  ans++;
    }
    cout<<ans;
    return 0;
}
