#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[200000],cnt=0;
char a[200000];
string ans="",tmp;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b[i]>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i];j++)
        {
            ans+=a[i];
        }
    }
    tmp=ans;
    reverse(ans.begin(),ans.end());
    if(tmp==ans)
    {
        cout<<0;
        return 0;
    }
    ans=tmp;
    if(n==1)
    {
        cout<<0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i]=ans[i]+'j';
            cnt++;
            reverse(ans.begin(),ans.end());
            if(tmp==ans)
            {
                cout<<cnt;
                return 0;
            }
            ans=tmp;
        }

    }
}
