#include<bits/stdc++.h>
using namespace std;
int n,ai,ans=0;
string ci,s,t;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>ai>>ci;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=ai;j++)
        {
            cin>>s[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=ai;j>=1;j--)
        {
            cin>>t[i];
            if(s.size()==t.size())
            {
                cout<<"0";
                break;
            }
            else
            {
                if(s[i]!=t[i])
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
