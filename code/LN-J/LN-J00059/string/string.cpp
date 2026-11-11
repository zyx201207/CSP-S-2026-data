#include <bits/stdc++.h>
using namespace std;
int n;
int a[200000];
char c;
string s;
int ss=0;
int ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c;
        for(int j=0;j<a[i];j++)
        {
            s+=c;
        }
        ss+=a[i];
    }

    for(int i=0;i<ss/2;i++)
    {
        if(s[i]!=s[ss-1-i])
        {
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
