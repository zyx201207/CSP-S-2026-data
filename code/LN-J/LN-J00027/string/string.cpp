#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
char s[2000000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans=0;
    long long ss=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=ss+1;j<=ss+a[i];j++)
        {
            s[j]=c[i];
        }
        ss=ss+a[i];
    }
    for(int i=1;i<=ss/2;i++)
    {
        if(s[i]!=s[ss-i+1])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
