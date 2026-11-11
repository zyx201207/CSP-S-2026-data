#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    cin>>n;
    int b=1;
    char c;
    int ans=0;
    char s[1000010];
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int i=b;i<=b+a;i++)
        {
            s[i]=c;
        }
        b+=a;
    }
    for(int i=1;i<=b/2;i++)
    {
        if(s[i]!=s[b-i+1])
        {
            ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
