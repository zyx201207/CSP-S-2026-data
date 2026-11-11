#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    string s1,s2,s;
    for(int i=1;i<=n;i++)
    {
        int A;
        char C;
        cin>>A>>C;
        sum+=A;
        for(int i=1;i<=A;i++)
        {
            s=s+C;
        }
    }
    cout<<s;
    int mid=(sum+1)/2;
    int ans;
    if(mid%2==0)
    {
        for(int i=1;i<=mid;i++)
        {
            s1+=s[i];
        }
        for(int i=mid+1;i<=sum;i++)
        {
            s2+=s[i];
        }
        ans=mid;
    }
    else{
        for(int i=1;i<=mid-1;i++)
        {
            s1+=s[i];
        }
        for(int i=mid+1;i<=sum;i++)
        {
            s2+=s[i];
        }
        ans=mid-1;
    }
    for(int i=0;i<s1.length();i++)
    {
        for(int j=0;j<=s2.length();j--)
        {
            if(s1[i]==s2[j])
            {
                ans--;
            }
        }
    }
    cout<<ans;
}