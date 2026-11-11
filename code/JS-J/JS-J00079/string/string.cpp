#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int ans=0;
    char c[1100000000];
    long long a[1100000000];
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    int sum=s.size();
    if(s.size()%2==0)
    {
        for(int i=0;i<sum/2;i++)
        {
            if(s[i]!=s[sum-1-i])
            {
                ans++;
            }
        }
    }
    else
    {
        for(int i=0;i<sum/2+1;i++)
        {
            if(s[i]!=s[sum-1-i])
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
