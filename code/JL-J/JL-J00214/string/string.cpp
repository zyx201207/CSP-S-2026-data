
#include<bits/stdc++.h>
using namespace std;
#define int long long
string c[100005];
int a[100005];
string ans;
signed main()
{
   freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int t=1;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i]>>c[i];
        if(c[i]!=c[i-1])
        {
            t=0;
        }

        //ans+=s;
    }
    if(t)
    {
        cout<<0;
        return 0;
    }
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=a[i];j++)
        {
            ans+=c[i];
        }
    }
    int l=ans.size();
    int cnt=0;
    for(int i=0;i<=ans.size()/2;i++)
    {
        if(ans[i]!=ans[ans.size()-i-1])
        {
            //cout<<l-i<<' ';
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

