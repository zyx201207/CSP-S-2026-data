#include<bits/stdc++.h>
using namespace std;
struct Node
{
    long long cnt;
    char c;
}p[2000000];
long long n,num,ans=0;
string s="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>p[i].cnt>>p[i].c;
        num+=p[i].cnt;
    }
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=p[i].cnt;j++)
            s+=p[i].c;
    for(long long i=0;i<=(num)/2-1;i++)
    {
        if(s[i]!=s[num-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
