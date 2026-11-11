#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int a[1000005]={0};
    char b[1000005]={0};
    int flag=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        if(i==1)
        {
            if(b[i]!=b[i-1])
            {
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        cout<<0;
        return 0;
    }
    string s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            s=s+b[i];
        }
    }
    long long cnt=0;
    if(s.size()%2==0)
    {
        for(int i=0;i<(s.size())/2;i++)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                cnt++;
            }
        }
    }
    else if(s.size()%2==1)
    {
        for(int i=0;i<(s.size())/2;i++)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
