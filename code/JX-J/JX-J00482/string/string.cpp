#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char s[100000010];
long long ans,x=1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        char c;
        cin>>a[i]>>c;
        for(long long j=x;j<=a[i]+x-1;j++)
            s[j]=c;
        x+=a[i];
    }
    x--;
    for(long long i=1;i<=x/2;i++)
    {
        if(x-i+1<=x&&s[i]!=s[x-i+1])
            ans++;
    }
    cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}
