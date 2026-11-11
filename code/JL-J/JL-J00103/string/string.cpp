#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],num,cnt;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    map<int,char>mp;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i]>>c[i];
        for(int j=num+1;j<=num+a[i];j++)mp[j]=c[i];
        num+=a[i];
    }
    if(num%2==1)
    {
        long long z=num/2+1;
        for(int i=z-1;i>=1;i--)if(mp[i]!=mp[2*z-i])cnt++;
        cout<<cnt;
    }
    else
    {
        long long z=num/2;
        for(int i=1;i<=z;i++)if(mp[i]!=mp[num-i+1])cnt++;
        cout<<cnt;
    }

}
