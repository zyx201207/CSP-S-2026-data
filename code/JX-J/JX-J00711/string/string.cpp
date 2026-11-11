#include<bits/stdc++.h>
using namespace std;
string x,s;
long long n,a[200010],lens=0,t,b,ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>x;
        for(int j=1;j<=a[i];j++)
        {
            s+=x;
            lens++;
        }
    }
    t=0;
    b=lens-1;
    while(t<b)
    {
        if(s[t]!=s[b])
        {
            ans++;
        }
        t++,b--;
    }
    cout<<ans;
    return 0;
}
