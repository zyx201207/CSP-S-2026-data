#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,t,ans=0;
    cin>>n;
    long long a[n+1];
    char b[n+1];
    string s="";
    for(long long i=1;i<=n;i++)
    cin>>a[i]>>b[i];
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=a[i];j++)
        s+=b[i];
        t=s.size();
        if(t%2==1)
        {
            for(long long i=0;i<(t-1)/2;i++)
                if(s[i]!=s[t-1-i])ans++;
        }
        if(t%2==0)
        {
            for(long long i=0;i<=(t/2-1);i++)
                if(s[i]!=s[t-1-i])ans++;
        }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
