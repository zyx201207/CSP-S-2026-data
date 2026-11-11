#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[n+100];
    char c[n+100];
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    long long l=0,ans=0,k=1;
    for(int i=1;i<=n;i++)
        l+=a[i];
    char s[l+100];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=a[i];j++,k++)
            s[k]=c[i];
    long long top=1,bot=l;
    while(top<bot)
    {
        if(s[bot]!=s[top])
            ans++;
        top++;
        bot--;
    }
    cout<<ans;

    return 0;
}
