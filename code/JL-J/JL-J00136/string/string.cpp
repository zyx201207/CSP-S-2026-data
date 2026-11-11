#include <bits/stdc++.h>
using namespace std;
long long a[10010];
char c[10010];
string s1;
int main()
{

    long long n,cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s1+=c[i];
        }
        cnt+=a[i];
    }
    long long l=0,r=n-1;
    for(int i=0;i<=cnt/2;i++)
    {
        if(s1[l]!=s1[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;
}
